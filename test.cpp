#include <conio.h>
#include <iostream>
using namespace std;


#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_CENTER 3
#define KEY_TAB 9
#define KEY_SHIFT 16
#define KEY_CTRL 17
#define KEY_ALT 18
#define KEY_CAPS_LOCK 20
#define KEY_ESC 27
#define KEY_SPACE_BAR 32
#define KEY_END 35
#define KEY_DEBUT 36
#define KEY_LEFT_ARROW 37
#define KEY_UP_ARROW 38
#define KEY_RIGHT_ARROW 39
#define KEY_DOWN_ARROW 40
#define KEY_PRINT 42
#define KEY_SNAPSHOT 44
#define KEY_DELETE 46
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_A 65
#define KEY_B 66
#define KEY_C 67
#define KEY_D 68
#define KEY_E 69
#define KEY_F 70
#define KEY_G 71
#define KEY_H 72
#define KEY_I 73
#define KEY_J 74
#define KEY_K 75
#define KEY_L 76
#define KEY_M 77
#define KEY_N 78
#define KEY_O 79
#define KEY_P 80
#define KEY_Q 81
#define KEY_R 82
#define KEY_S 83
#define KEY_T 84
#define KEY_U 85
#define KEY_V 86
#define KEY_W 87
#define KEY_X 88
#define KEY_Y 89
#define KEY_Z 90
#define KEY_LEFT_WINDOWS 91
#define KEY_RIGHT_WINDOWS 92
#define KEY_NUM_PAD_0 96
#define KEY_NUM_PAD_1 97
#define KEY_NUM_PAD_2 98
#define KEY_NUM_PAD_3 99
#define KEY_NUM_PAD_4 100
#define KEY_NUM_PAD_5 101
#define KEY_NUM_PAD_6 102
#define KEY_NUM_PAD_7 103
#define KEY_NUM_PAD_8 104
#define KEY_NUM_PAD_9 105
#define KEY_F1 112
#define KEY_F2 113
#define KEY_F3 114
#define KEY_F4 115
#define KEY_F5 116
#define KEY_F6 117
#define KEY_F7 118
#define KEY_F8 119
#define KEY_F9 120
#define KEY_F10 121
#define KEY_F11 122
#define KEY_F12 123



int main()
{
    int c = 0;
    while (1)
    {
        c = 0;

        switch ((c = _getch())) {
        //case KEY_UP:
        //    cout << endl << "Up" << endl;//key up
        //    break;
        //case KEY_DOWN:
        //    cout << endl << "Down" << endl;   // key down
        //    break;
        //case KEY_LEFT:
        //    cout << endl << "Left" << endl;  // key left
        //    break;
        //case KEY_RIGHT:
        //    cout << endl << "Right" << endl;  // key right
        //    break;
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
        case KEY_A:
            cout << endl << "A" << endl; // A
            break;
        case KEY_B:
            cout << endl << "B" << endl; // B
            break;
        case KEY_C:
            cout << endl << "C" << endl; // C
            break;
        case KEY_D:
            cout << endl << "D" << endl; // D
            break;
        case KEY_E:
            cout << endl << "E" << endl; // E
            break;
        case KEY_F:
            cout << endl << "F" << endl; // F
            break;
        case KEY_G:
            cout << endl << "G" << endl; // G
            break;
        case KEY_H:
            cout << endl << "H" << endl; // H
            break;
        case KEY_I:
            cout << endl << "I" << endl; // I
            break;
        case KEY_J:
            cout << endl << "J" << endl; // J
            break;
        case KEY_K:
            cout << endl << "K" << endl; // K
            break;
        case KEY_L:
            cout << endl << "L" << endl; // L
            break;
        case KEY_M:
            cout << endl << "M" << endl; // M
            break;
        case KEY_N:
            cout << endl << "N" << endl; // N
            break;
        case KEY_O:
            cout << endl << "O" << endl; // O
            break;
        case KEY_P:
            cout << endl << "P" << endl; // P
            break;
        case KEY_Q:
            cout << endl << "Q" << endl; // Q
            break;
        case KEY_R:
            cout << endl << "R" << endl; // R
            break;
        case KEY_S:
            cout << endl << "S" << endl; // S
            break;
        case KEY_T:
            cout << endl << "T" << endl; // T
            break;
        case KEY_U:
            cout << endl << "U" << endl; // U
            break;
        case KEY_V:
            cout << endl << "V" << endl; // V
            break;
        case KEY_W:
            cout << endl << "W" << endl; // W
            break;
        case KEY_X:
            cout << endl << "X" << endl; // X
            break;
        case KEY_Y:
            cout << endl << "Y" << endl; // Y
            break;
        case KEY_Z:
            cout << endl << "Z" << endl; // Z
            break;
        case KEY_NUM_PAD_0:
            cout << endl << "Numeric pad 0" << endl; // Numeric pad 0
            break;
        case KEY_NUM_PAD_1:
            cout << endl << "Numeric pad 1" << endl; // Numeric pad 1
            break;
        case KEY_NUM_PAD_2:
            cout << endl << "Numeric pad 2" << endl; // Numeric pad 2
            break;
        case KEY_NUM_PAD_3:
            cout << endl << "Numeric pad 3" << endl; // Numeric pad 3
            break;
        case KEY_NUM_PAD_4:
            cout << endl << "Numeric pad 4" << endl; // Numeric pad 4
            break;
        case KEY_NUM_PAD_5:
            cout << endl << "Numeric pad 5" << endl; // Numeric pad 5
            break;
        case KEY_NUM_PAD_6:
            cout << endl << "Numeric pad 6" << endl; // Numeric pad 6
            break;
        case KEY_NUM_PAD_7:
            cout << endl << "Numeric pad 7" << endl; // Numeric pad 7
            break;
        case KEY_NUM_PAD_8:
            cout << endl << "Numeric pad 8" << endl; // Numeric pad 8
            break;
        case KEY_NUM_PAD_9:
            cout << endl << "Numeric pad 9" << endl; // Numeric pad 9
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
        case KEY_F7:
            cout << endl << "F7" << endl; // F7
            break;
        case KEY_F8:
            cout << endl << "F8" << endl; // F8
            break;
        case KEY_F9:
            cout << endl << "F9" << endl; // F9
            break;
        case KEY_F10:
            cout << endl << "F10" << endl; // F10
            break;
        case KEY_F11:
            cout << endl << "F11" << endl; // F11
            break;
        case KEY_F12:
            cout << endl << "F12" << endl; // F12
            break;
        case MOUSE_LEFT:
            cout << endl << "Mouse Left" << endl; // Mouse Left
            break;
        case MOUSE_RIGHT:
            cout << endl << "Mouse Right" << endl; // Mouse Right
            break;
        case KEY_TAB:
            cout << endl << "Tab" << endl; // Tab
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
        case KEY_ESC:
            cout << endl << "Echape" << endl; // échape
            break;
        case KEY_SPACE_BAR:
            cout << endl << "Space bar" << endl; // Space bar
            break;
        case KEY_END:
            cout << endl << "End" << endl; // End
            break;
        case KEY_DEBUT:
            cout << endl << "Debut" << endl; // Debut
            break;
        case KEY_LEFT_ARROW:
            cout << endl << "Left Arrow" << endl; // Left Arrow
            break;
        case KEY_UP_ARROW:
            cout << endl << "Up Arrow" << endl; // Up Arrow
            break;
        case KEY_RIGHT_ARROW:
            cout << endl << "Right Arrow" << endl; // Right Arrow
            break;
        case KEY_DOWN_ARROW:
            cout << endl << "Down Arrow" << endl; // Down Arrow
            break;
        case KEY_PRINT:
            cout << endl << "Print" << endl; // Print
            break;
        case KEY_SNAPSHOT:
            cout << endl << "Snapshot" << endl; // Snapshot
            break;
        case KEY_DELETE:
            cout << endl << "Delete" << endl; // Delete
            break;
        case KEY_LEFT_WINDOWS:
            cout << endl << "Left Windows button" << endl; // Left Windows button
            break;
        case KEY_RIGHT_WINDOWS:
            cout << endl << "Right Windows button" << endl; // Right Windows button
            break;
        default:
            break;
        }

    }

    return 0;
}
