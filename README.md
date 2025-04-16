# CEF Issue 3803 - "cannot allocate memory in static TLS block"
Applies for some Linux ARM devices.

## Build Instructions
1. `cmake -S . -B out/build/Debug`
2. `cmake --build out/build/Debug --config Debug -- "-j" "19"`

## Use Instructions
### x64
1. Install Ubuntu 24
2. Run `sudo apt install -y sudo libxkbcommon-x11-0 libc6 libc6-dev libgtk2.0-0 libnss3 libatk-bridge2.0-0 libx11-xcb1 libxcb-dri3-0 libdrm-common libgbm1 libasound2t64 libxrender1 libfontconfig1 libxshmfence1 libgdiplus libva-dev`
3. Run `./SimpleConsole` and observe no error

## CEF
You can acquire CEF builds from https://cef-builds.spotifycdn.com/index.html

### CEF 109
I suggest trying CEF 109 first, as it should only have a TLS header of 440 bytes
> jd@DESKTOP-5T1RIMS:/mnt/c/space$ readelf -Wl libcef.so | grep -E 'PhysAddr|TLS'
  Type           Offset   VirtAddr           PhysAddr           FileSiz  MemSiz   Flg Align
  TLS            0xb101a80 0x000000000b121a80 0x000000000b121a80 0x000080 0x0001b8 R   0x40
