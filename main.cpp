#include <iostream>
#include <stdio.h>
#include <intrin.h>

#include "return_spoofer.h"

#pragma section(".text")
__declspec(allocate(".text")) const unsigned char jmp_rdx[] = { 0xFF, 0x27 };

void abc() {
	std::cout << "return address: " << _ReturnAddress() << std::endl; // should print address of jmp_rdx
}

int main() {
	std::cout << "main: " << std::hex << (void*)main << std::endl;
	std::cout << "jmp_rdx: " << (void*)jmp_rdx << std::endl;
	return_spoofer::spoof_call(jmp_rdx, &abc);
}