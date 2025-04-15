# CEF Issue 3803 - "cannot allocate memory in static TLS block"
Applies for some Linux ARM devices.

## CEF
You can acquire CEF builds from https://cef-builds.spotifycdn.com/index.html

### CEF 109
I suggest trying CEF 109 first, as it should only have a TLS header of 440 bytes
> jd@DESKTOP-5T1RIMS:/mnt/c/space$ readelf -Wl libcef.so | grep -E 'PhysAddr|TLS'
  Type           Offset   VirtAddr           PhysAddr           FileSiz  MemSiz   Flg Align
  TLS            0xb101a80 0x000000000b121a80 0x000000000b121a80 0x000080 0x0001b8 R   0x40
