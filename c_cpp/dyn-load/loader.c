#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void *handle;
	void (*run)(void);
	void (*print)(char *);
	void (*func)(const char *fmt,...);
	
	handle = dlopen("libplugin.so", RTLD_LAZY);
	if (!handle)
	{
		puts("Error: Unable to open plugin.");
		exit(1);
	}
	
	dlerror();
	
	*(void **)(&run) = dlsym(handle, "start");
	*(void **)(&print) = dlsym(handle, "print");
	*(void **)(&func) = dlsym(handle, "func");
	
	(*run)();
	(*print)("It works!");
	(*func)("print");
	(*func)("print_int", 10);
	
	dlclose(handle);
	return 0;
}
