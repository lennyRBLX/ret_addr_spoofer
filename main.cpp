#include <iostream>
#include <stdio.h>
#include <intrin.h>

#include "return_spoofer.h"

#pragma section(".text")
__declspec(allocate(".text")) const unsigned char jmp_rdx[] = { 0xFF, 0x27 };

void abc() {
	std::cout << "return address: " << _ReturnAddress() << std::endl; // should print address of jmp_rdx
}

// limitations: only works on x64, works on only one nonvolatile register (forced to find a part of the module that uses same shell as jmp_rdx), cannot work on any address, easily detected via signature

int main() {
	std::cout << "main: " << std::hex << (void*)main << std::endl;
	std::cout << "jmp_rdx: " << (void*)jmp_rdx << std::endl;
	return_spoofer::spoof_call(jmp_rdx, &abc);
}