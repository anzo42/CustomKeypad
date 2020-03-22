#include <Arduino.h>
#include <Keypad.h>
#include <Keyboard.h>

static void Zapis();
static void Undo();
static void Redo();
static void BrushBigger();
static void BrushSmaller();
static void BrushThicker();
static void BrushThinner();
static void ZoomIn();
static void ZoomOut();
static void Escape();
static void SelectAll();
static void DeSelectAll();
static void MergeDown();

static const byte rows = 5;
static const byte cols = 4;
char keys[rows][cols] = {
    {'A', '/', '*', '-'},
    {'7', '8', '9', '+'},
    {'4', '5', '6', 'B'},
    {'1', '2', '3', 'C'},
    {'0', '*', 'G', ','} //* na klawiaturze niema tego znaku
};

byte rowPins[rows] = {15, 14, 16, 10, 7};
byte colPins[cols] = {6, 5, 4, 3};
Keypad keypad = Keypad{makeKeymap(keys), rowPins, colPins, rows, cols};

int main()
{

#ifdef DEBUG
      Serial.begin(9600);
#else
      Keyboard.begin();
#endif

      while (1)
      {
#ifdef DEBUG2
            char key = keypad.getKey();
            if (key != NULL)
                  Serial.println(key);
#else
            switch (keypad.getKey())
            {
            case 'A':
                  Zapis();
                  break;
            case 'C':
                  Undo();
                  break;
            case 'B':
                  Redo();
                  break;
            case '8':
                  BrushBigger();
                  break;
            case '9':
                  BrushSmaller();
                  break;
            case '5':
                  BrushThicker();
                  break;
            case '6':
                  BrushThinner();
                  break;
            case '+':
                  ZoomIn();
                  break;
            case '-':
                  ZoomOut();
                  break;
            case '0':
                  Escape();
                  break;
            case '*':
                  SelectAll();
                  break;
            case '/':
                  DeSelectAll();
                  break;
            case '1':
                  MergeDown();
                  break;

            default:
                  break;
            }
#endif
      }
}

static void Zapis()
{
#ifdef DEBUG
      Serial.println("Zapis");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('s');
      Keyboard.releaseAll();
#endif
}

static void Undo()
{
#ifdef DEBUG
      Serial.println("Undo");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('z');
      Keyboard.releaseAll();
#endif
}

static void Redo()
{
#ifdef DEBUG
      Serial.println("Redo");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('z');
      Keyboard.releaseAll();
#endif
}

static void BrushBigger()
{
#ifdef DEBUG
      Serial.println("Brush_Rozmiar++");
#else
      Keyboard.press(']');
      Keyboard.releaseAll();
#endif
}

static void BrushSmaller()
{
#ifdef DEBUG
      Serial.println("Brush_Rozmiar--");
#else
      Keyboard.press('[');
      Keyboard.releaseAll();
#endif
}

static void BrushThicker()
{
#ifdef DEBUG
      Serial.println("Brush_Nacisk++");
#else
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(']');
      Keyboard.releaseAll();
#endif
}

static void BrushThinner()
{
#ifdef DEBUG
      Serial.println("Brush_Nacisk--");
#else
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('[');
      Keyboard.releaseAll();
#endif
}

static void ZoomIn()
{
#ifdef DEBUG
      Serial.println("Zoom++");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('+');
      Keyboard.releaseAll();
#endif
}

static void ZoomOut()
{
#ifdef DEBUG
      Serial.println("Zoom--");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('-');
      Keyboard.releaseAll();
#endif
}

static void Escape()
{
#ifdef DEBUG
      Serial.println("Escape");
#else
      Keyboard.press(KEY_ESC);
      Keyboard.releaseAll();
#endif
}

static void SelectAll()
{
#ifdef DEBUG
      Serial.println("Zaznacz_wszysto");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('a');
      Keyboard.releaseAll();
#endif
}

static void DeSelectAll()
{
#ifdef DEBUG
      Serial.println("Odznacz_wszystko");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('d');
      Keyboard.releaseAll();
#endif
}

static void MergeDown()
{
  #ifdef DEBUG
      Serial.println("Merge_down");
#else
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('e');
      Keyboard.releaseAll();
#endif    
}