#include <stdio.h>
#include <dlfcn.h>

int main (int c, char *v[])
{
   void* g_libcef_handle = dlopen("./libcef.so", RTLD_LAZY | RTLD_LOCAL);
   if (!g_libcef_handle) {
     fprintf(stderr, "dlerror %s\n", dlerror());
   }
   return 0;
}
