// ThiAs file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

    @8192
    D = A // D = 8192
    @pix_num
    M = D // pix_num = 8192

    @R0
    M = 0 // R0 = 0
    
    (LOOP)
    @KBD
    D = M // KEY = 0
    @KEY_PUSHE
    D;JNE
    
    (KEY_NOT_PUSHE)
    @R1
    M = 0 // R1 = 0
    @UPDATE
    0;JMP

    (KEY_PUSHE)
    @R1
    M = 1 // R1 = 1

    (UPDATE)
    @R0
    D = M // D = R0
    @R1
    D = D - M // D = R0 - R1
    @LOOP
    D;JEQ // D == 0 -> LOOP
    @i
    M = 0 // i = 0
    @R1
    D = M // D = i
    @R0
    M = D
    @UNFILL
    D;JEQ

    (FILL)
    @i
    D = M // D = i
    @pix_num
    D = M - D
    @LOOP
    D;JLT
    @SCREEN
    A = A + D
    M = -1
    @i
    MD = M + 1
    @FILL
    0;JMP

    (UNFILL)
    @i
    D = M
    @pix_num
    D = M - D
    @LOOP
    D;JLT
    @SCREEN
    A = A + D
    M = 0
    @i
    MD = M + 1
    @UNFILL
    0;JMP
