#include <conio.h>
#include <iostream>
using namespace std;


#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_CENTER 3
#define KEY_BACK_SPACE 8 //OK
#define KEY_TAB 9 //OK
#define KEY_SHIFT 16
#define KEY_CTRL 17
#define KEY_ALT 18
#define KEY_CAPS_LOCK 20
#define KEY_ESC 27 //OK
#define KEY_SPACE_BAR 32 //OK
#define KEY_EXCLAMATION 33 //OK
#define KEY_HASHTAG 35 //OK
#define KEY_DOLLAR 36 //OK
#define KEY_ET_COMM 38 //OK
#define KEY_APOST 39 //OK
#define KEY_PARENTHESIS_OPEN 40 //OK
#define KEY_PARENTHESIS_CLOSE 41 //OK
#define KEY_STAR 42 //OK
#define KEY_PLUS 43 //OK
#define KEY_COMA 44 //OK
#define KEY_MINUS 45 //OK
#define KEY_DOT 46 //OK
#define KEY_SLASH 47 //OK
#define KEY_0 48 //OK
#define KEY_1 49 //OK
#define KEY_2 50 //OK
#define KEY_3 51 //OK
#define KEY_4 52 //OK
#define KEY_5 53 //OK
#define KEY_6 54 //OK
#define KEY_7 55 //OK
#define KEY_8 56 //OK
#define KEY_9 57 //OK
#define KEY_DOUBLE_DOT 58 //OK
#define KEY_F1 59 //OK
#define KEY_F2 60 //OK
#define KEY_F3 61 //OK
#define KEY_F4 62 //OK
#define KEY_F5 63 //OK
#define KEY_F6 64 //OK
#define KEY_A_MAJ 65 //OK
#define KEY_B_MAJ 66 //OK
#define KEY_C_MAJ 67 //OK
#define KEY_D_MAJ 68 //OK
#define KEY_E_MAJ 69 //OK
#define KEY_F_MAJ 70 //OK
#define KEY_G_MAJ 71 //OK
#define KEY_H_MAJ 72 //OK
#define KEY_I_MAJ 73 //OK
#define KEY_J_MAJ 74 //OK
#define KEY_K_MAJ 75 //OK
#define KEY_L_MAJ 76 //OK
#define KEY_M_MAJ 77 //OK
#define KEY_N_MAJ 78 //OK
#define KEY_O_MAJ 79 //OK
#define KEY_P_MAJ 80 //OK
#define KEY_Q_MAJ 81 //OK
#define KEY_R_MAJ 82 //OK
#define KEY_S_MAJ 83 //OK
#define KEY_T_MAJ 84 //OK
#define KEY_U_MAJ 85 //OK
#define KEY_V_MAJ 86 //OK
#define KEY_W_MAJ 87 //OK
#define KEY_X_MAJ 88 //OK
#define KEY_Y_MAJ 89 //OK
#define KEY_Z_MAJ 90 //OK
#define KEY_BRACKET_OPEN 91 //OK
#define KEY_BACK_SLASH 92 //OK
#define KEY_BRACKET_CLOSE 93 //OK
#define KEY_A_MIN 97 //OK
#define KEY_B_MIN 98 //OK
#define KEY_C_MIN 99 //OK
#define KEY_D_MIN 100 //OK
#define KEY_E_MIN 101 //OK
#define KEY_F_MIN 102 //OK
#define KEY_G_MIN 103 //OK
#define KEY_H_MIN 104 //OK
#define KEY_I_MIN 105 //OK
#define KEY_J_MIN 106 //OK
#define KEY_K_MIN 107 //OK
#define KEY_L_MIN 108 //OK
#define KEY_M_MIN 109 //OK
#define KEY_N_MIN 110 //OK
#define KEY_O_MIN 111 //OK
#define KEY_P_MIN 112 //OK
#define KEY_Q_MIN 113 //OK
#define KEY_R_MIN 114 //OK
#define KEY_S_MIN 115 //OK
#define KEY_T_MIN 116 //OK
#define KEY_U_MIN 117 //OK
#define KEY_V_MIN 118 //OK
#define KEY_W_MIN 119 //OK
#define KEY_X_MIN 120 //OK
#define KEY_Y_MIN 121 //OK
#define KEY_Z_MIN 122 //OK
#define KEY_ACCOLADE_OPEN 123 //OK
#define KEY_VERTICAL_BAR 124 //OK
#define KEY_ACCOLADE_CLOSE 125 //OK
#define KEY_ACCENT_GRAVE 126 //OK
#define KEY_F7 129
#define KEY_E_ACCENT_AIGU 130 //OK
#define KEY_F9 131
#define KEY_F10 132
#define KEY_A_ACCENT 133 //OK
#define KEY_F12 134 //OK
#define KEY_C_CEDILLA 135 //OK
#define KEY_E_ACCENT_GRAVE 138 //OK
#define KEY_NUM_LOCK 144


int main()
{
    int c = 0;
    while (1)
    {
        c = _getch();

        if (c == 0 || c == 224) { // if the first value is esc
            switch (_getch()) { // the real value
            case 72:
                cout << endl << "Up Arrow" << endl; // The value for up arrow is 72
                break;
            case 80:
                cout << endl << "Down Arrow" << endl; // The value for down arrow is 80
                break;
            case 77:
                cout << endl << "Right Arrow" << endl; // The value for right arrow is 77
                break;
            case 75:
                cout << endl << "Left Arrow" << endl; // The value for left arrow is 75
                break;
            default:
                cout << endl << "Code de la touche spéciale : " << c << endl; // Renvoit le code
                break;
            }
        }
        
        
        
        
        
        switch (c) {
        case KEY_1:
            cout << endl << "1" << endl; // 1
            break;
        case KEY_2:
            cout << endl << "2" << endl; // 2
            break;
        case KEY_3:
            cout << endl << "3" << endl; // 3
            break;
        case KEY_4:
            cout << endl << "4" << endl; // 4
            break;
        case KEY_5:
            cout << endl << "5" << endl; // 5
            break;
        case KEY_6:
            cout << endl << "6" << endl; // 6
            break;
        case KEY_7:
            cout << endl << "7" << endl; // 7
            break;
        case KEY_8:
            cout << endl << "8" << endl; // 8
            break;
        case KEY_9:
            cout << endl << "9" << endl; // 9
            break;
        case KEY_0:
            cout << endl << "0" << endl; // 0
            break;
        case KEY_A_MAJ:
            cout << endl << "A" << endl; // A
            break;
        case KEY_B_MAJ:
            cout << endl << "B" << endl; // B
            break;
        case KEY_C_MAJ:
            cout << endl << "C" << endl; // C
            break;
        case KEY_D_MAJ:
            cout << endl << "D" << endl; // D
            break;
        case KEY_E_MAJ:
            cout << endl << "E" << endl; // E
            break;
        case KEY_F_MAJ:
            cout << endl << "F" << endl; // F
            break;
        case KEY_G_MAJ:
            cout << endl << "G" << endl; // G
            break;
        case KEY_H_MAJ:
            cout << endl << "H" << endl; // H
            break;
        case KEY_I_MAJ:
            cout << endl << "I" << endl; // I
            break;
        case KEY_J_MAJ:
            cout << endl << "J" << endl; // J
            break;
        case KEY_K_MAJ:
            cout << endl << "K" << endl; // K
            break;
        case KEY_L_MAJ:
            cout << endl << "L" << endl; // L
            break;
        case KEY_M_MAJ:
            cout << endl << "M" << endl; // M
            break;
        case KEY_N_MAJ:
            cout << endl << "N" << endl; // N
            break;
        case KEY_O_MAJ:
            cout << endl << "O" << endl; // O
            break;
        case KEY_P_MAJ:
            cout << endl << "P" << endl; // P
            break;
        case KEY_Q_MAJ:
            cout << endl << "Q" << endl; // Q
            break;
        case KEY_R_MAJ:
            cout << endl << "R" << endl; // R
            break;
        case KEY_S_MAJ:
            cout << endl << "S" << endl; // S
            break;
        case KEY_T_MAJ:
            cout << endl << "T" << endl; // T
            break;
        case KEY_U_MAJ:
            cout << endl << "U" << endl; // U
            break;
        case KEY_V_MAJ:
            cout << endl << "V" << endl; // V
            break;
        case KEY_W_MAJ:
            cout << endl << "W" << endl; // W
            break;
        case KEY_X_MAJ:
            cout << endl << "X" << endl; // X
            break;
        case KEY_Y_MAJ:
            cout << endl << "Y" << endl; // Y
            break;
        case KEY_Z_MAJ:
            cout << endl << "Z" << endl; // Z
            break;
        case KEY_A_MIN:
            cout << endl << "a" << endl; // a
            break;
        case KEY_B_MIN:
            cout << endl << "b" << endl; // b
            break;
        case KEY_C_MIN:
            cout << endl << "c" << endl; // c
            break;
        case KEY_D_MIN:
            cout << endl << "d" << endl; // d
            break;
        case KEY_E_MIN:
            cout << endl << "e" << endl; // e
            break;
        case KEY_F_MIN:
            cout << endl << "f" << endl; // f
            break;
        case KEY_G_MIN:
            cout << endl << "g" << endl; // g
            break;
        case KEY_H_MIN:
            cout << endl << "h" << endl; // h
            break;
        case KEY_I_MIN:
            cout << endl << "i" << endl; // i
            break;
        case KEY_J_MIN:
            cout << endl << "j" << endl; // j
            break;
        case KEY_K_MIN:
            cout << endl << "k" << endl; // k
            break;
        case KEY_L_MIN:
            cout << endl << "l" << endl; // l
            break;
        case KEY_M_MIN:
            cout << endl << "m" << endl; // m
            break;
        case KEY_N_MIN:
            cout << endl << "n" << endl; // n
            break;
        case KEY_O_MIN:
            cout << endl << "o" << endl; // o
            break;
        case KEY_P_MIN:
            cout << endl << "p" << endl; // p
            break;
        case KEY_Q_MIN:
            cout << endl << "q" << endl; // q
            break;
        case KEY_R_MIN:
            cout << endl << "r" << endl; // r
            break;
        case KEY_S_MIN:
            cout << endl << "s" << endl; // s
            break;
        case KEY_T_MIN:
            cout << endl << "t" << endl; // t
            break;
        case KEY_U_MIN:
            cout << endl << "u" << endl; // u
            break;
        case KEY_V_MIN:
            cout << endl << "v" << endl; // v
            break;
        case KEY_W_MIN:
            cout << endl << "w" << endl; // w
            break;
        case KEY_X_MIN:
            cout << endl << "x" << endl; // x
            break;
        case KEY_Y_MIN:
            cout << endl << "y" << endl; // y
            break;
        case KEY_Z_MIN:
            cout << endl << "z" << endl; // z
            break;
        case KEY_F1:
            cout << endl << "F1" << endl; // F1
            break;
        case KEY_F2:
            cout << endl << "F2" << endl; // F2
            break;
        case KEY_F3:
            cout << endl << "F3" << endl; // F3
            break;
        case KEY_F4:
            cout << endl << "F4" << endl; // F4
            break;
        case KEY_F5:
            cout << endl << "F5" << endl; // F5
            break;
        case KEY_F6:
            cout << endl << "F6" << endl; // F6
            break;
        case KEY_F12:
            cout << endl << "F12" << endl; // F12
            break;
        case KEY_E_ACCENT_AIGU:
            cout << endl << "é" << endl; // E accent aigu minuscule
            break;
        case KEY_E_ACCENT_GRAVE:
            cout << endl << "è" << endl; // E accent grave minuscule
            break;
        case KEY_C_CEDILLA:
            cout << endl << "ç" << endl; // C cédille minuscule
            break;
        case KEY_A_ACCENT:
            cout << endl << "à" << endl; // A minuscule accent grave
            break;
        case KEY_BACK_SPACE:
            cout << endl << "Back Space" << endl; // Back Space
            break;
        case KEY_TAB:
            cout << endl << "Tab" << endl; // Tab
            break;
        case KEY_ESC:
            cout << endl << "Escape" << endl; // Escape
            break;
        case KEY_SPACE_BAR:
            cout << endl << "Space bar" << endl; // Space bar
            break;
        case KEY_HASHTAG:
            cout << endl << "#" << endl; // Hashtag
            break;
        case KEY_DOLLAR:
            cout << endl << "$" << endl; // Dollar
            break;
        case KEY_ET_COMM:
            cout << endl << "&" << endl; // Et commercial
            break;
        case KEY_APOST:
            cout << endl << "'" << endl; // Apostrophe
            break;
        case KEY_PARENTHESIS_OPEN:
            cout << endl << "(" << endl; // Opening parenthesis
            break;
        case KEY_PARENTHESIS_CLOSE:
            cout << endl << ")" << endl; // Closing parenthesis
            break;
        case KEY_PLUS:
            cout << endl << "+" << endl; // Plus
            break;
        case KEY_MINUS:
            cout << endl << "-" << endl; // Minus
            break;
        case KEY_STAR:
            cout << endl << "*" << endl; // Star
            break;
        case KEY_COMA:
            cout << endl << "," << endl; // Coma
            break;
        case KEY_DOT:
            cout << endl << "." << endl; // Dot
            break;
        case KEY_DOUBLE_DOT:
            cout << endl << ":" << endl; // Double dot
            break;
        case KEY_BRACKET_OPEN:
            cout << endl << "[" << endl; // Opening bracket
            break;
        case KEY_ACCOLADE_OPEN:
            cout << endl << "{" << endl; // Opening accolade
            break;
        case KEY_BRACKET_CLOSE:
            cout << endl << "]" << endl; // Closing bracket
            break;
        case KEY_ACCOLADE_CLOSE:
            cout << endl << "}" << endl; // Closing accolade
            break;
        case KEY_VERTICAL_BAR:
            cout << endl << "|" << endl; // Vertical bar
            break;
        case KEY_ACCENT_GRAVE:
            cout << endl << "à" << endl; // A accent grave
            break;
        case KEY_EXCLAMATION:
            cout << endl << "!" << endl; // Exclamation point
            break;
        case KEY_SLASH:
            cout << endl << "/" << endl; // Slash
            break;
        case KEY_BACK_SLASH:
            cout << endl << " \\" << endl; // Back slash
            break;




        //Ne fonctionne pas
        case MOUSE_LEFT:
            cout << endl << "Mouse Left" << endl; // Mouse Left
            break;
        case MOUSE_RIGHT:
            cout << endl << "Mouse Right" << endl; // Mouse Right
            break;
        case KEY_SHIFT:
            cout << endl << "Shift" << endl; // Shift
            break;
        case KEY_CTRL:
            cout << endl << "Ctrl" << endl; // Ctrl
            break;
        case KEY_ALT:
            cout << endl << "Alt" << endl; // Alt
            break;
        case KEY_CAPS_LOCK:
            cout << endl << "Caps Lock" << endl; // Caps Lock
            break;
        case KEY_NUM_LOCK:
            cout << endl << "Num Lock" << endl; // Num Lock
            break;


        //Quand on tape la touche en question ça renvoit une autre valeur
        case KEY_F7:
            cout << endl << "F7" << endl; // Renvoit A
            break;
        case KEY_F9:
            cout << endl << "F9" << endl; // Renvoit C
            break;
        case KEY_F10:
            cout << endl << "F10" << endl; // Renvoit D
            break;



        default:
            cout << endl << "Code de la touche : " << c << endl; // Renvoit le code
            break;
        }

    }

    return 0;
}
