%macro write_consol 2 
  mov eax, SYS_WRITE
  mov ebx, 1
  mov ecx, %1
  mov edx, %2
  int 0x80
%endmacro

%macro read_consol 2 
  mov eax, SYS_READ
  mov ebx, 1
  mov ecx, %1
  mov edx, %2
  int 0x80
%endmacro

%macro open_file 2 
  mov eax, SYS_OPEN
  mov ebx, %1
  mov ecx, %2 
  mov edx, NUL
  int 0x80
%endmacro

%macro read_file 3 
  mov eax, SYS_READ
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int 0x80
%endmacro

%macro write_file 3 
  mov eax, SYS_WRITE
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int 0x80
%endmacro

%macro close_file 1
	mov eax, SYS_CLOSE
  mov ebx, %1
  int 0x80
%endmacro

%macro fseek_file 3
	mov eax, SYS_LSEEK
  mov ebx, %1
  mov ecx, %2
  mov edx, %3
  int 0x80
%endmacro

%macro comparison_of_strings 3
  mov esi, %1
  mov edi, %2
  mov ecx, %3
  cld
  repe cmpsb
%endmacro

%macro clone_of_string 3
  mov ecx, %1
  mov esi, %2
  mov edi, %3
  cld
  rep movsb
%endmacro

%macro sum 6
  mov esi, %1
  mov ecx, %2
  clc

  %3:
    mov al, [ %4 + esi ]
    adc al, [ %5 + esi ]
    aaa

    pushf
    or al, 0x30
    popf
            
    mov [ %3 + esi ], al
    dec esi
  rep
%endmacro

%macro before_sub 2
  mov esi, %1
  mov ecx, %2
  clc
%endmacro

%macro sub 2
  mov al, [ %1 + esi ]
  adc al, [ %2 + esi ]
  aas

  pushf
  or al, 0x30
  popf
            
  mov [ %1 + esi ], al
  dec esi
%endmacro