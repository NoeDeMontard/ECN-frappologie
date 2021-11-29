#include <conio.h>
#include <iostream>
#include "constantes.h"
using namespace std;

void keyWrapper(int c, int encore) {

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
        cout << "1"; // 1
        break;
    case KEY_2:
        cout << "2"; // 2
        break;
    case KEY_3:
        cout << "3"; // 3
        break;
    case KEY_4:
        cout << "4"; // 4
        break;
    case KEY_5:
        cout << "5"; // 5
        break;
    case KEY_6:
        cout << "6"; // 6
        break;
    case KEY_7:
        cout << "7"; // 7
        break;
    case KEY_8:
        cout << "8"; // 8
        break;
    case KEY_9:
        cout << "9"; // 9
        break;
    case KEY_0:
        cout << "0"; // 0
        break;
    case KEY_A_MAJ:
        cout << "A"; // A
        break;
    case KEY_B_MAJ:
        cout << "B"; // B
        break;
    case KEY_C_MAJ:
        cout << "C"; // C
        break;
    case KEY_D_MAJ:
        cout << "D"; // D
        break;
    case KEY_E_MAJ:
        cout << "E"; // E
        break;
    case KEY_F_MAJ:
        cout << "F"; // F
        break;
    case KEY_G_MAJ:
        cout << "G"; // G
        break;
    case KEY_H_MAJ:
        cout << "H"; // H
        break;
    case KEY_I_MAJ:
        cout << "I"; // I
        break;
    case KEY_J_MAJ:
        cout << "J"; // J
        break;
    case KEY_K_MAJ:
        cout << "K"; // K
        break;
    case KEY_L_MAJ:
        cout << "L"; // L
        break;
    case KEY_M_MAJ:
        cout << "M"; // M
        break;
    case KEY_N_MAJ:
        cout << "N"; // N
        break;
    case KEY_O_MAJ:
        cout << "O"; // O
        break;
    case KEY_P_MAJ:
        cout << "P"; // P
        break;
    case KEY_Q_MAJ:
        cout << "Q"; // Q
        break;
    case KEY_R_MAJ:
        cout << "R"; // R
        break;
    case KEY_S_MAJ:
        cout << "S"; // S
        break;
    case KEY_T_MAJ:
        cout << "T"; // T
        break;
    case KEY_U_MAJ:
        cout << "U"; // U
        break;
    case KEY_V_MAJ:
        cout << "V"; // V
        break;
    case KEY_W_MAJ:
        cout << "W"; // W
        break;
    case KEY_X_MAJ:
        cout << "X"; // X
        break;
    case KEY_Y_MAJ:
        cout << "Y"; // Y
        break;
    case KEY_Z_MAJ:
        cout << "Z"; // Z
        break;
    case KEY_A_MIN:
        cout << "a"; // a
        break;
    case KEY_B_MIN:
        cout << "b"; // b
        break;
    case KEY_C_MIN:
        cout << "c"; // c
        break;
    case KEY_D_MIN:
        cout << "d"; // d
        break;
    case KEY_E_MIN:
        cout << "e"; // e
        break;
    case KEY_F_MIN:
        cout << "f"; // f
        break;
    case KEY_G_MIN:
        cout << "g"; // g
        break;
    case KEY_H_MIN:
        cout << "h"; // h
        break;
    case KEY_I_MIN:
        cout << "i"; // i
        break;
    case KEY_J_MIN:
        cout << "j"; // j
        break;
    case KEY_K_MIN:
        cout << "k"; // k
        break;
    case KEY_L_MIN:
        cout << "l"; // l
        break;
    case KEY_M_MIN:
        cout << "m"; // m
        break;
    case KEY_N_MIN:
        cout << "n"; // n
        break;
    case KEY_O_MIN:
        cout << "o"; // o
        break;
    case KEY_P_MIN:
        cout << "p"; // p
        break;
    case KEY_Q_MIN:
        cout << "q"; // q
        break;
    case KEY_R_MIN:
        cout << "r"; // r
        break;
    case KEY_S_MIN:
        cout << "s"; // s
        break;
    case KEY_T_MIN:
        cout << "t"; // t
        break;
    case KEY_U_MIN:
        cout << "u"; // u
        break;
    case KEY_V_MIN:
        cout << "v"; // v
        break;
    case KEY_W_MIN:
        cout << "w"; // w
        break;
    case KEY_X_MIN:
        cout << "x"; // x
        break;
    case KEY_Y_MIN:
        cout << "y"; // y
        break;
    case KEY_Z_MIN:
        cout << "z"; // z
        break;
    case KEY_COMA_POINT:
        cout << ";"; // Coma point
        break;
    case KEY_CHEVRON_OPEN:
        cout << "<"; // Opening chevron
        break;
    case KEY_EQUAL:
        cout << "="; // F3
        break;
    case KEY_CHEVRON_CLOSE:
        cout << ">"; // Closing chevron
        break;
    case KEY_INTERROGATION:
        cout << "?"; // Interrogation point
        break;
    case KEY_AROBASE:
        cout << "@"; // Arobase
        break;
    case KEY_F12:
        cout << "F12"; // F12
        break;
    case KEY_E_ACCENT_AIGU:
        cout << "é"; // E accent aigu minuscule
        break;
    case KEY_E_ACCENT_GRAVE:
        cout << "è"; // E accent grave minuscule
        break;
    case KEY_C_CEDILLA:
        cout << "ç"; // C cédille minuscule
        break;
    case KEY_A_ACCENT:
        cout << "à"; // A minuscule accent grave
        break;
    case KEY_BACK_SPACE:
        cout << "Back Space"; // Back Space, vrai problème pour gérer l'effacement du dernier caractère
        break;
    case KEY_TAB:
        cout << "   "; // Tab
        break;
    case KEY_ENTER:
        cout << endl; // Enter
        break;
    case KEY_QUOTE:
        cout << "\""; // Enter
        break;
    case KEY_ESC:
        encore = 0; // Escape
        break;
    case KEY_SPACE_BAR:
        cout << " "; // Space bar
        break;
    case KEY_HASHTAG:
        cout << "#"; // Hashtag
        break;
    case KEY_DOLLAR:
        cout << "$"; // Dollar
        break;
    case KEY_ET_COMM:
        cout << "&"; // Et commercial
        break;
    case KEY_APOST:
        cout << "'"; // Apostrophe
        break;
    case KEY_PARENTHESIS_OPEN:
        cout << "("; // Opening parenthesis
        break;
    case KEY_PARENTHESIS_CLOSE:
        cout << ")"; // Closing parenthesis
        break;
    case KEY_PLUS:
        cout << "+"; // Plus
        break;
    case KEY_MINUS:
        cout << "-"; // Minus
        break;
    case KEY_STAR:
        cout << "*"; // Star
        break;
    case KEY_COMA:
        cout << ","; // Coma
        break;
    case KEY_DOT:
        cout << "."; // Dot
        break;
    case KEY_DOUBLE_DOT:
        cout << ":"; // Double dot
        break;
    case KEY_BRACKET_OPEN:
        cout << "["; // Opening bracket
        break;
    case KEY_ACCOLADE_OPEN:
        cout << "{"; // Opening accolade
        break;
    case KEY_BRACKET_CLOSE:
        cout << "]"; // Closing bracket
        break;
    case KEY_ACCOLADE_CLOSE:
        cout << "}"; // Closing accolade
        break;
    case KEY_VERTICAL_BAR:
        cout << "|"; // Vertical bar
        break;
    case KEY_ACCENT_GRAVE:
        cout << "à"; // A accent grave
        break;
    case KEY_EXCLAMATION:
        cout << "!"; // Exclamation point
        break;
    case KEY_SLASH:
        cout << "/"; // Slash
        break;
    case KEY_BACK_SLASH:
        cout << " \\"; // Back slash
        break;
    case KEY_UNDERSCORE:
        cout << "_"; // Undersocre
        break;
    case KEY_U_ACCENT_GRAVE:
        cout << "ù"; // U accent grave
        break;
    case KEY_DEGREE:
        cout << "°"; // Degree
        break;
    case KEY_POURCENT:
        cout << "%"; // Pourcent
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

}
