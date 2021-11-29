#include <conio.h>
#include <iostream>
#include <string>
#include "constantes.h"
using namespace std;

string keyWrapper(int c, bool encore) {

    //Special keys case
    if (c == 0 || c == 224) { // Fisrt value returned by special keys
        switch (_getch()) { // the real value they returned
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
            break;
        }
    }

    //General case
    switch (c) {
    case KEY_1:
        return "1"; // 1
        break;
    case KEY_2:
        return "2"; // 2
        break;
    case KEY_3:
        return "3"; // 3
        break;
    case KEY_4:
        return "4"; // 4
        break;
    case KEY_5:
        return "5"; // 5
        break;
    case KEY_6:
        return "6"; // 6
        break;
    case KEY_7:
        return "7"; // 7
        break;
    case KEY_8:
        return "8"; // 8
        break;
    case KEY_9:
        return "9"; // 9
        break;
    case KEY_0:
        return "0"; // 0
        break;
    case KEY_A_MAJ:
        return "A"; // A
        break;
    case KEY_B_MAJ:
        return "B"; // B
        break;
    case KEY_C_MAJ:
        return "C"; // C
        break;
    case KEY_D_MAJ:
        return "D"; // D
        break;
    case KEY_E_MAJ:
        return "E"; // E
        break;
    case KEY_F_MAJ:
        return "F"; // F
        break;
    case KEY_G_MAJ:
        return "G"; // G
        break;
    case KEY_H_MAJ:
        return "H"; // H
        break;
    case KEY_I_MAJ:
        return "I"; // I
        break;
    case KEY_J_MAJ:
        return "J"; // J
        break;
    case KEY_K_MAJ:
        return "K"; // K
        break;
    case KEY_L_MAJ:
        return "L"; // L
        break;
    case KEY_M_MAJ:
        return "M"; // M
        break;
    case KEY_N_MAJ:
        return "N"; // N
        break;
    case KEY_O_MAJ:
        return "O"; // O
        break;
    case KEY_P_MAJ:
        return "P"; // P
        break;
    case KEY_Q_MAJ:
        return "Q"; // Q
        break;
    case KEY_R_MAJ:
        return "R"; // R
        break;
    case KEY_S_MAJ:
        return "S"; // S
        break;
    case KEY_T_MAJ:
        return "T"; // T
        break;
    case KEY_U_MAJ:
        return "U"; // U
        break;
    case KEY_V_MAJ:
        return "V"; // V
        break;
    case KEY_W_MAJ:
        return "W"; // W
        break;
    case KEY_X_MAJ:
        return "X"; // X
        break;
    case KEY_Y_MAJ:
        return "Y"; // Y
        break;
    case KEY_Z_MAJ:
        return "Z"; // Z
        break;
    case KEY_A_MIN:
        return "a"; // a
        break;
    case KEY_B_MIN:
        return "b"; // b
        break;
    case KEY_C_MIN:
        return "c"; // c
        break;
    case KEY_D_MIN:
        return "d"; // d
        break;
    case KEY_E_MIN:
        return "e"; // e
        break;
    case KEY_F_MIN:
        return "f"; // f
        break;
    case KEY_G_MIN:
        return "g"; // g
        break;
    case KEY_H_MIN:
        return "h"; // h
        break;
    case KEY_I_MIN:
        return "i"; // i
        break;
    case KEY_J_MIN:
        return "j"; // j
        break;
    case KEY_K_MIN:
        return "k"; // k
        break;
    case KEY_L_MIN:
        return "l"; // l
        break;
    case KEY_M_MIN:
        return "m"; // m
        break;
    case KEY_N_MIN:
        return "n"; // n
        break;
    case KEY_O_MIN:
        return "o"; // o
        break;
    case KEY_P_MIN:
        return "p"; // p
        break;
    case KEY_Q_MIN:
        return "q"; // q
        break;
    case KEY_R_MIN:
        return "r"; // r
        break;
    case KEY_S_MIN:
        return "s"; // s
        break;
    case KEY_T_MIN:
        return "t"; // t
        break;
    case KEY_U_MIN:
        return "u"; // u
        break;
    case KEY_V_MIN:
        return "v"; // v
        break;
    case KEY_W_MIN:
        return "w"; // w
        break;
    case KEY_X_MIN:
        return "x"; // x
        break;
    case KEY_Y_MIN:
        return "y"; // y
        break;
    case KEY_Z_MIN:
        return "z"; // z
        break;
    case KEY_COMA_POINT:
        return ";"; // Coma point
        break;
    case KEY_CHEVRON_OPEN:
        return "<"; // Opening chevron
        break;
    case KEY_EQUAL:
        return "="; // F3
        break;
    case KEY_CHEVRON_CLOSE:
        return ">"; // Closing chevron
        break;
    case KEY_INTERROGATION:
        return "?"; // Interrogation point
        break;
    case KEY_AROBASE:
        return "@"; // Arobase
        break;
    case KEY_F12:
        return "F12"; // F12
        break;
    case KEY_E_ACCENT_AIGU:
        return "é"; // E accent aigu minuscule
        break;
    case KEY_E_ACCENT_GRAVE:
        return "è"; // E accent grave minuscule
        break;
    case KEY_C_CEDILLA:
        return "ç"; // C cédille minuscule
        break;
    case KEY_A_ACCENT:
        return "à"; // A minuscule accent grave
        break;
    case KEY_BACK_SPACE:
        return "Back Space"; // Back Space, vrai problème pour gérer l'effacement du dernier caractère
        break;
    case KEY_TAB:
        return "	"; // Tab
        break;
    case KEY_ENTER:
        encore = 0;
        return "\n"; // Enter
        break;
    case KEY_QUOTE:
        return "\""; // Enter
        break;
    case KEY_ESC:
        return "\esc"; // Escape
        break;
    case KEY_SPACE_BAR:
        return " "; // Space bar
        break;
    case KEY_HASHTAG:
        return "#"; // Hashtag
        break;
    case KEY_DOLLAR:
        return "$"; // Dollar
        break;
    case KEY_ET_COMM:
        return "&"; // Et commercial
        break;
    case KEY_APOST:
        return "'"; // Apostrophe
        break;
    case KEY_PARENTHESIS_OPEN:
        return "("; // Opening parenthesis
        break;
    case KEY_PARENTHESIS_CLOSE:
        return ")"; // Closing parenthesis
        break;
    case KEY_PLUS:
        return "+"; // Plus
        break;
    case KEY_MINUS:
        return "-"; // Minus
        break;
    case KEY_STAR:
        return "*"; // Star
        break;
    case KEY_COMA:
        return ","; // Coma
        break;
    case KEY_DOT:
        return "."; // Dot
        break;
    case KEY_DOUBLE_DOT:
        return ":"; // Double dot
        break;
    case KEY_BRACKET_OPEN:
        return "["; // Opening bracket
        break;
    case KEY_ACCOLADE_OPEN:
        return "{"; // Opening accolade
        break;
    case KEY_BRACKET_CLOSE:
        return "]"; // Closing bracket
        break;
    case KEY_ACCOLADE_CLOSE:
        return "}"; // Closing accolade
        break;
    case KEY_VERTICAL_BAR:
        return "|"; // Vertical bar
        break;
    case KEY_ACCENT_GRAVE:
        return "à"; // A accent grave
        break;
    case KEY_EXCLAMATION:
        return "!"; // Exclamation point
        break;
    case KEY_SLASH:
        return "/"; // Slash
        break;
    case KEY_BACK_SLASH:
        return " \\"; // Back slash
        break;
    case KEY_UNDERSCORE:
        return "_"; // Undersocre
        break;
    case KEY_U_ACCENT_GRAVE:
        return "ù"; // U accent grave
        break;
    case KEY_DEGREE:
        return "°"; // Degree
        break;
    case KEY_POURCENT:
        return "%"; // Pourcent
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
        //cout << endl << "Code de la touche : " << c << endl; // Return the key code
        break;
    }
	return "";
}
