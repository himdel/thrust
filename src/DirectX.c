
/* Written by Peter Ekberg, peda@lysator.liu.se */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#if defined(HAVE_GETOPT_H) && defined(HAVE_GETOPT_LONG_ONLY)
# include <getopt.h>
#elif !defined(HAVE_GETOPT_LONG_ONLY)
# include "getopt.h"
#endif

#include <Windows.h>
#include <DDraw.h>
#include "../DirectX/resource.h"

#include "thrust.h"
#include "fast_gr.h"
#include "gr_drv.h"
#include "options.h"

#define PSTARTX ((WIDTH-PUSEX)>>1)
#define PSTARTY ((HEIGHT-PUSEY-24)>>1)

HINSTANCE hInstance;
HINSTANCE hPrevInstance;
int iCmdShow;
ATOM atomWndClass = 0;
HANDLE hWnd = 0;
LPDIRECTDRAW lpDD;
LPDIRECTDRAWPALETTE lpDDP;
LPDIRECTDRAWSURFACE lpDDS;
word WIDTH;
word HEIGHT;

extern LRESULT __stdcall WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

extern int main(int argc, char **argv);

int WINAPI
WinMain(HINSTANCE hInst,  // handle to current instance
	HINSTANCE hPrevInst,  // handle to previous instance
	LPSTR lpCmdLine,      // pointer to command line
	int nCmdShow)         // show state of window
{
  UNREFERENCED_PARAMETER(lpCmdLine);

  hPrevInstance = hPrevInst;
  hInstance = hInst;
  iCmdShow = nCmdShow;

  main(__argc, __argv);

  return 0;
}

byte scr[64000];
byte scrstate=0;

void
storescr()
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  word y;
  byte *tmp;

  if(!lpDDS)
    return;
  if(scrstate)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT | DDLOCK_READONLY, NULL);
  if(hr != DD_OK)
    return;

  tmp=(byte *)ddsd.lpSurface + PSTARTX + ddsd.lPitch*PSTARTY;
  for(y=0; y<HEIGHT; y++)
    memcpy(scr + y*320, tmp + y*ddsd.lPitch, 320);

  IDirectDrawSurface_Unlock(lpDDS, NULL);

  scrstate = 1;
}

void
paintscr()
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  word y;
  byte *tmp;

  if(!lpDDS)
    return;
  if(!scrstate)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
  if(hr != DD_OK)
    return;

  tmp=(byte *)ddsd.lpSurface + PSTARTX + ddsd.lPitch*PSTARTY;
  for(y=0; y<HEIGHT; y++)
    memcpy(tmp + y*ddsd.lPitch, scr + y*320, 320);

  IDirectDrawSurface_Unlock(lpDDS, NULL);

  scrstate=0;
}

void
clearscr(void)
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  word y;

  if(!lpDDS)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
  if(hr != DD_OK)
    return;

  for(y=0; y<HEIGHT; y++)
    memset((byte *)ddsd.lpSurface + y*ddsd.lPitch, 0, WIDTH);

  IDirectDrawSurface_Unlock(lpDDS, NULL);
}

void
putarea(byte *source,
	int x, int y, int width, int height, int bytesperline,
	int destx, int desty)
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  byte *tmp;
  int res;
  int dy;

  if(!lpDDS)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
  if(hr != DD_OK)
    return;

  res=PSTARTX+destx+ddsd.lPitch*(PSTARTY+desty);
  if(bytesperline==320 && width==320 && WIDTH==320 && ddsd.lPitch==320 && x==0 && destx==0) {
    memcpy((byte *)ddsd.lpSurface + desty*WIDTH, source + y*width, height*width);
  }
  else {
    tmp=source+y*bytesperline+x;

    for(dy=y; dy<y+height; res+=ddsd.lPitch, dy++, tmp+=bytesperline) {
      memcpy((byte *)ddsd.lpSurface + res, tmp, width);
    }
  }

  IDirectDrawSurface_Unlock(lpDDS, NULL);
}

void
hline(int x1, int y, int x2, byte color)
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  int x;

  if(!lpDDS)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
  if(hr != DD_OK)
    return;

  for(x=min(x1, x2); x<=max(x1, x2); x++)
    *((byte *)ddsd.lpSurface + (PSTARTY+y)*ddsd.lPitch + PSTARTX+x) = color;

  IDirectDrawSurface_Unlock(lpDDS, NULL);
}

void
vline(int x, int y1, int y2, byte color)
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  int y;

  if(!lpDDS)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
  if(hr != DD_OK)
    return;

  for(y=min(y1, y2); y<=max(y1, y2); y++)
    *((byte *)ddsd.lpSurface + (PSTARTY+y)*ddsd.lPitch + PSTARTX+x) = color;

  IDirectDrawSurface_Unlock(lpDDS, NULL);
}

void
putpixel(int x, int y, byte color)
{
  HRESULT hr;
  DDSURFACEDESC ddsd;

  if(!lpDDS)
    return;

  hr = IDirectDrawSurface_IsLost(lpDDS);
  if(hr == DDERR_SURFACELOST)
    hr = IDirectDrawSurface_Restore(lpDDS);
  if(hr != DD_OK)
    return;

  ddsd.dwSize = sizeof(ddsd);
  hr = IDirectDrawSurface_Lock(lpDDS, NULL, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, NULL);
  if(hr != DD_OK)
    return;

  *((byte *)ddsd.lpSurface + (PSTARTY+y)*ddsd.lPitch + PSTARTX+x) = color;

  IDirectDrawSurface_Unlock(lpDDS, NULL);
}

void
syncscreen(void)
{
  HRESULT hr;

  if(!lpDD)
    return;

  hr = IDirectDraw_WaitForVerticalBlank(lpDD, DDWAITVB_BLOCKBEGIN, NULL);
  if(hr == DDERR_UNSUPPORTED) {
    BOOL bIsInVB;
    do {
      hr = IDirectDraw_GetVerticalBlankStatus(lpDD, &bIsInVB);
      if(bIsInVB)
	continue;
    } while(hr == DD_OK);
  }
}

void
displayscreen(void)
{
}

void
fadepalette(int first, int last, byte *RGBtable, int fade, int flag)
{
  static PALETTEENTRY tmpPal[256];
  int entries,i;
  PALETTEENTRY *c;
  byte *d;

  entries=last-first+1;
  
  c=tmpPal;
  d=(byte *)RGBtable;
  i=0;

  while(i<entries) {
    c->peRed   = (*d * fade) >> 6;
    c->peGreen = (*(d+1) * fade) >> 6;
    c->peBlue  = (*(d+2) * fade) >> 6;
    if(++i<entries) {
      c++;
      d+=3;
    }
  }

  if(flag)
    syncscreen();

  IDirectDrawPalette_SetEntries(lpDDP, 0, first, entries, tmpPal);
}

void
fade_in(void)
{
  int i;

  if(PSTARTY>0 && PSTARTX>0) {
    hline(-3, -3, PUSEX+2, 1);
    hline(-4, -4, PUSEX+3, 2);
    hline(-5, -5, PUSEX+4, 3);
    hline(-3, PUSEY+26, PUSEX+2, 3);
    hline(-4, PUSEY+27, PUSEX+3, 2);
    hline(-5, PUSEY+28, PUSEX+4, 1);
    vline(-3, -3, PUSEY+26, 1);
    vline(-4, -4, PUSEY+27, 2);
    vline(-5, -5, PUSEY+28, 3);
    vline(PUSEX+2, -3, PUSEY+26, 3);
    vline(PUSEX+3, -4, PUSEY+27, 2);
    vline(PUSEX+4, -5, PUSEY+28, 1);
  }
  else if(PSTARTY>0) {
    hline(0, -3, PUSEX-1, 1);
    hline(0, -4, PUSEX-1, 2);
    hline(0, -5, PUSEX-1, 3);
    hline(0, PUSEY+26, PUSEX-1, 3);
    hline(0, PUSEY+27, PUSEX-1, 2);
    hline(0, PUSEY+28, PUSEX-1, 1);
  }

  for(i=1; i<=64; i++)
    fadepalette(0, 255, bin_colors, i, 1);
}

void
fade_out(void)
{
  int i;

  for(i=64; i; i--)
    fadepalette(0, 255, bin_colors, i, 1);
  clearscr();
  usleep(500000L);
}



void
graphics_preinit(void)
{
}

int
graphicsinit(int argc, char **argv)
{
  HRESULT hr;
  DDSURFACEDESC ddsd;
  PALETTEENTRY ape[256];
  int i;
  MSG msg;

  if(!hPrevInstance) {
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(hInstance, (char *)IDI_THRUST);
    wc.hCursor = LoadCursor(hInstance, (char *)IDC_NOCURSOR);
    wc.hbrBackground = GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = "ThurstMenu";
    wc.lpszClassName = "ThrustClass";
    wc.hIconSm = wc.hIcon;

    atomWndClass = RegisterClassEx(&wc);
    if(!atomWndClass)
      return 0;
  }

  hWnd = CreateWindow("ThrustClass", "Thrust",
    WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME), CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
  if(!hWnd)
    return 0;

  ShowWindow(hWnd, iCmdShow);
  UpdateWindow(hWnd);

  hr = DirectDrawCreate(NULL, &lpDD, NULL);
  if(hr != DD_OK)
    return 0;
  /*
    LPDIRECTDRAW2 lpDD;
    hr = lpDD1->QueryInterface(IID_IDirectDraw2, (void **)&lpDD);
    if(hr != DD_OK)
    return 0;
    lpDD1->Release();
  */
  hr = IDirectDraw_SetCooperativeLevel(lpDD, hWnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
  if(hr != DD_OK)
    return 0;
  hr = IDirectDraw_SetDisplayMode(lpDD, 320, 200, 8);//, 0, 0);//DDSDM_STANDARDVGAMODE);
  if(hr != DD_OK) {
    hr = IDirectDraw_SetDisplayMode(lpDD, 640, 480, 8);//, 0 ,0);
    if(hr != DD_OK)
      return 0;
    WIDTH = 640;
    HEIGHT = 480;
  }
  else {
    WIDTH = 320;
    HEIGHT = 200;
  }

  ddsd.dwSize = sizeof(ddsd);
  ddsd.dwFlags = DDSD_CAPS;
  ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_VIDEOMEMORY;// | DDSCAPS_LOCALVIDMEM;

  hr = IDirectDraw_CreateSurface(lpDD, &ddsd, &lpDDS, NULL);
  if(hr != DD_OK)
    return 0;

  for(i = 0; i<256; i++) {
    ape[i].peRed = 0;
    ape[i].peGreen = 0;
    ape[i].peBlue = 0;
  }
  hr = IDirectDraw_CreatePalette(lpDD, DDPCAPS_8BIT | DDPCAPS_ALLOW256, ape, &lpDDP, NULL);
  if(hr != DD_OK)
    return 0;

  hr = IDirectDrawSurface_SetPalette(lpDDS, lpDDP);
  if(hr != DD_OK)
    return 0;

  while(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
    if(!GetMessage(&msg, NULL, 0, 0))
      break;
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    continue;
  }

  fadepalette(0, 255, bin_colors, 1, 0);

  return 0;
}

int
graphicsclose(void)
{
  IDirectDrawPalette_Release(lpDDP);
  lpDDP = NULL;
  IDirectDrawSurface_Release(lpDDS);
  lpDDS = NULL;
  IDirectDraw_RestoreDisplayMode(lpDD);
  IDirectDraw_Release(lpDD);
  lpDD = NULL;

  DestroyWindow(hWnd);
  if(atomWndClass)
    UnregisterClass((char *)atomWndClass, NULL);

  return 0;
}

char *
graphicsname(void)
{
  static char name[] = "DirectX";

  return name;
}
