
/*  前景色和背景色编号:
    
    0-   黑色
	1-   白色
    2-   红色
	3-   绿色
	4-   蓝色
	5-   黄色
	6-   粉红色
	7-   青色
	8-   暗红色
	9-   暗绿色
	10-  暗蓝色
	11-  暗黄色 
	12-  暗粉红色
	13-  暗青色
	14-  暗白色	
	15-  淡黑色   

*/

#pragma once
#include <windows.h>

#define UP 0
#define DOWN 1



//  屏幕类

class  Screen
{
private:
 
	//HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD cursor;
	COORD pos;
	DWORD buf;

	void Get_cursor_position();
	
public:
    
	int  text_color_num;
    int  text_Bgcolor_num;
            
    int  Character_color_num;
    int  Character_Bgcolor_num;

	int  screen_Bgcolor_num; 
	
	int wide,heigh;

	Screen();
	~Screen();	
		
	void SetSize(SHORT xSize, SHORT ySize);
	void ShowOrHideCursor(int i);
	void SetTitle(char *ConsoleTitle);
	void Pause();

	void TextAttribute(int a,int b);
	void DisplayText(int x,int y,char *str);
	void CharacterAttribute(int a,int b);
	void DisplayCharacter(int x,int y,char ch,int num);
	void DisplayCharacter(COORD pos,char ch,int num);
		
	void Paint_screen();
	void Paint_screen(int Bgcolor_num);
	void Clear_screen();
	void PaintCharacter(COORD pos,int chcolor_num,int chBgcolor_num,int wide);

	void SetTextColor(int wTextColor_num);
	void SetTextColorAndTextBackgroundColor(int wTextColor_num,int wTextBackgroundColor_num);
		
	void MoveCursorTo(int x,int y);
	void MoveCursorTo(COORD pos);
	
	void DrawBar_H(int y,int Left,int Right,int bar_color_num);
	void DrawBar_V(int x,int Top,int Bottom,int bar_color_num);	
	
	void Write(char *str);
	void Write(int num);
	void Write(float num);
	void WriteLine(char *str);
	void WriteLine(int num);
	void WriteLine(float num);
	void Read(char *str,int length);
	void Read(int *num);
	void Read(float *num);
		
	void Close_handle();
	HANDLE CreateNewScreenBuffer();
	void SetActiveBuffer(HANDLE hOut);
};


//  表格类


class Form
{
private:
     
	//HANDLE hOut;
    COORD pos;
	DWORD buf;

public:
    int  form_color_num;
    int  form_Bgcolor_num;
	
	Form(void);
	~Form(void);

    void Attribute(int a,int b);
    void SetRectangular(SMALL_RECT *rect,int a,int b,int c,int d);
    void DrawBox(SMALL_RECT rc);
    void DrawSeparatorBar_H(int y,int Left,int Right); 
    void DrawSeparatorBar_V(int x,int Top,int Bottom);   
    void DrawForm(int left,int top,int column,int line,int Form_wide,int Form_high);
};


//  按钮类

class Button 
{
private:
    
	//HANDLE hOut;  
	COORD pos;   
	DWORD buf;

	void Get_mouse_position();

public:
    
	int cx0;
    int cy0;
    char name[MAX_PATH];

	int  button_color_num;
    int  button_Bgcolor_num;

	int  FillCharacter_color_num;
    int  FillCharacter_Bgcolor_num;

	Button(int x=0,int y=0,char name1[]="wangli");
	~Button();

	void Attribute(int a,int b);
	void Display_button();	
	int MousePosition_At_button();
	void PaintText_button(int color_num,int Bgcolor_num);
	void FillCharacterAttribute(int a,int b);
	void FillCharacter(char ch);
};


//  事件类

class Event 
{
private:
	DWORD dwOldMode;
	DWORD numRead; /*  返回已读取的记录数 */
	DWORD wangli;
public:		
	Event();	
	~Event();
	
	BOOL PeekEvent();
	void ReadEvent();
	
	bool Mouse_Event();
	bool Right_Button_Pressed();
	bool Right_Button_Released();	
	bool Double_Click();
	bool Mouse_Moved();
	bool Left_Button_Pressed();
	bool Left_Button_Released();
	bool Button_Released();
	void Get_mouse_position();
	bool Mouse_Wheel_Up();
	bool Mouse_Wheel_Down();

	bool Key_Event();
	BOOL Key_Down();
	BOOL Key_Up();
	char Get_ch();
	WORD Get_vk();
	DWORD Get_ck();
	DWORD Get_ck_mouse();
	
	void AddMouseMode();
	void RestoreMode();

	void WriteEvent();
	void WriteEvent_button(Button button);
	void FlushInputBuffer();
	void zero();	
};


//  文本框类

class Textbox
{
private:
     
	//HANDLE hOut;
	COORD pos;
    DWORD buf;

	char *jiequ(char *p,int wide);
	void Get_mouse_position();
	void ShowOrHideCursor(int i);

public:

    int cx0;
    int cy0;
    int wide;
	
	int  textbox_textcolor_num;
	int  textbox_textBgcolor_num;
    int  textbox_Bgcolor_num;

    int text_position;	
	bool Non_empty;

	Textbox(int x=1,int y=1,int wide1=1);
	~Textbox();

	void Attribute(int a,int b,int c);
	void DisplayString_textbox(char *str);	
	void Clear_textbox();
	void Paint_textbox();
	void PaintText_textbox(int textcolor,int textBgcolor);
	void PaintTextWithUnderline_textbox(int textcolor,int textBgcolor);
    void GetAttribute_textbox(WORD attr[]);
	void PutAttribute_textbox(WORD attr[]);
	int MousePosition_At_textbox();	
	char *InputString(bool display);
};


//  文件类

class File
{
public:

	char path0[MAX_PATH];
	
	File();

	int TotalLines(char *file);
	int File_is_empty(char *filename);
	void Getcwd();
	char *ReadFileLine(char *filename,int line);
	char *ReadFileToString(char filename[]);
	void HideFileOrFolder(char *name);
	void ShowFileOrFolder(char *name);
	void  daoxuwenjian(char *filename,char *daoxufilename);
};


//  窗口类


class Window : public File
{
private:
     
	//HANDLE hOut;
    
	COORD pos;
	DWORD buf;

	int up_Y;
	CHAR_INFO *text;

	char *jiequ(char *p,int wide);
	void MoveText(SMALL_RECT rc, int x, int y,int Bgcolor_num);	
	void Get_mouse_position();
	void DisplayFile_MultiPageWindow1(char *filename);
	void Get_window_pages(int lines);

public:

    int cx0;
    int cy0;
    int wide;
    int heigh;	
	   
    int  window_textcolor_num;
    int  window_textBgcolor_num;
    int  window_Bgcolor_num;
    
	Form frame;
	   
    Button   MultiPageButtonPageUp; 
	Button   MultiPageButtonPageDown;
	int page;
    int pages;

    Button   ScrollButtonUp;
	Button   ScrollButtonDown;

	Window(int x=1,int y=1,int wide1=1,int heigh1=1);
	~Window();

	void Attribute(int a,int b,int c,bool border,bool shadow,int shadow_colour_num);
	void Attribute1(bool border,bool shadow,int shadow_colour_num);
	void Attribute2(bool border,bool shadow,int shadow_colour_num);
	
	void Paint_window();
	void Paint_window(int Bgcolor_num);
	void PaintText_window(int textcolor,int textBgcolor);
	void Clear_window();
	void AddWindowBorder();
	void AddWindowWithinBorder();
	void AddShadow(bool border,int shadow_colour_num);

	void DisplayString_window(int x0,int y0,char *str);
	void DisplayStringEx_window(char *str);
		
	void DisplayFile_SinglePageWindow(char *filename);
	void DisplayFileEx_SinglePageWindow(char filename[]);
	void DisplayFile_ScrollWindow(char *filename);	
	void ScrollWindowText(int direction,char *filename);		
	void DisplayFile_MultiPageWindow(char *filename);
	void MultiPageWindowPageTurn_file(int direction,char *filename);
		
	void GetText_window();
	void PutText_window();	
	void GetText_window(CHAR_INFO buf[]);
	void PutText_window(CHAR_INFO buf[]);

	int MousePosition_At_window();
	int Point_At_window(COORD point);		
	void MoveWindow(int x, int y,int Bgcolor_num);
	int SuperPosition_window(Window window);
};


//  字符串链表类

typedef struct Node_string
{
      char name[MAX_PATH];
      struct Node_string *next;
}* PNode_string;

class LinkedList_string
{
public:

	PNode_string head;

	LinkedList_string(void);

	void CreateFromDirectory(const char *directory, char file_leibie[],bool full_name);
	void CreateFromFile(char file[]);
	PNode_string FindNode(int ip);
	int Length();
	void Print();
	char *NodeString(int ip);
	void AddNodeAtTail(char *str);
	void DeleteNode(int i);
	void Combine(LinkedList_string temp);
	void DeleteLb();
	void SaveToFile(char *filename);
	bool StringExsit(char *str);
};


//  列表框类

class Listbox 
{
private:
     
	//HANDLE hOut;
	
    COORD pos;
	DWORD buf;

	int num;      // 项目个数 ，初值为0 
    int index;       // 项目索引，初值为0 

	int up_Y;

    #define STR_SIZE 100

	void AddShadow(bool border,int shadow_colour_num);
	void AddListboxBorder();
	void Paint_listbox();
	void DisplayString_listbox(int x0,int y0,char *str);
	char *jiequ(char *p,int wide);
	void Get_mouse_position();
	void Get_listbox_index();	
	void MoveText(SMALL_RECT rc, int x, int y,int Bgcolor_num);
	void AddArrayto_MultiPageListbox1(char item[][STR_SIZE],int item_num);
	void Get_listbox_pages(int count);
	void Clear_listbox();
	void PaintText_listbox();
	void AddLbto_MultiPageListbox1(LinkedList_string Lb_name);

	Form frame;

public:

    int cx0;
    int cy0;
    int wide;
    int heigh;
     
    int  listbox_textcolor_num;
	int  listbox_textBgcolor_num;
	int  listbox_Bgcolor_num; 

    Button   MultiPageButtonPageUp; 
	Button   MultiPageButtonPageDown;
	int page;
	int pages;

    Button   ScrollButtonUp;
	Button   ScrollButtonDown;

	Textbox index_textbox;

	Listbox(int x=1,int y=1,int wide1=1,int heigh1=1);

	void Attribute(int a,int b,int c,bool border,bool shadow,int shadow_colour_num);
	void Attribute1(bool border,bool shadow,int shadow_colour_num);
	void Attribute2(bool border,bool shadow,int shadow_colour_num);
	
	void AddArrayto_SinglePageListbox(char item[][STR_SIZE],int item_num);
	void AddArrayto_ScrollListbox(char item[][STR_SIZE],int item_num);
	void ScrollListboxText_array(int direction,char item[][STR_SIZE],int item_num);
	void AddArrayto_MultiPageListbox(char item[][STR_SIZE],int item_num);
	void MultiPageListboxPageTurn_Array(int direction,char item[][STR_SIZE],int item_num);

	int MousePosition_At_listbox();	
	int SinglePageItemIndex();
	int ScrollItemIndex();
	int MultiPageItemIndex();
		
	void AddLbto_SinglePageListbox(LinkedList_string Lb_name);
	void AddLbto_ScrollListbox(LinkedList_string Lb_name);
	void ScrollListboxText_lb(int direction,LinkedList_string Lb_name);	
	void AddLbto_MultiPageListbox(LinkedList_string Lb_name);
	void MultiPageListboxPageTurn_Lb(int direction,LinkedList_string Lb_name);
};


//  滑条类

class Slider
{
private:
 
	//HANDLE hOut;
    
	COORD pos;
	DWORD buf;

	int  Character_color_num;
    int  Character_Bgcolor_num;

	int ch2_x;

	void DisplayCharacter(int x,int y,char ch,int num);
	void Get_mouse_position();

public:

    int cx0;
	int cy0;
	int length;	

	char ch1,ch2;
	int ch1_color_num,ch2_color_num,bgcolor_num;	

	float percent;

	Slider(int x=1,int y=1,int length1=1);
	~Slider();

	void Attribute(int a,int b,int c);	
	void Display();	
	int MousePostion_At_Slider();
	void Renew_mouse();
	void Renew_percent(float jd);
};