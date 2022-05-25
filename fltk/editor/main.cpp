#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <string>
#include <iostream>

//
// Global variables
//
static Fl_Text_Editor *editor;
std::string input_file = "";

//
// The various callback functions
//
// File menu
static void callback_file_new(Fl_Widget *w, void *) {
    puts("NEW");
}

static void callback_file_open(Fl_Widget *w, void *) {
    Fl_Native_File_Chooser chooser;
    chooser.title("Open File");
    chooser.type(Fl_Native_File_Chooser::BROWSE_FILE);
    
    switch (chooser.show()) {
        case -1: puts("ERROR"); break;
        case 1: break;  // Cancel
        default: {
            input_file = chooser.filename();
            editor->buffer()->loadfile(input_file.c_str());
        }
    }
}

static void callback_file_save(Fl_Widget *w, void *) {
    puts("SAVE");
}

static void callback_file_save_as(Fl_Widget *w, void *) {
    puts("SAVE AS");
}

static void callback_file_quit(Fl_Widget *w, void *) {
    puts("QUIT");
}

// Edit menu
static void callback_edit_cut(Fl_Widget *w, void *) { Fl_Text_Editor::kf_cut(0, editor); }
static void callback_edit_copy(Fl_Widget *w, void *) { Fl_Text_Editor::kf_copy(0, editor); }
static void callback_edit_paste(Fl_Widget *w, void *) { Fl_Text_Editor::kf_paste(0, editor); }
static void callback_edit_select_all(Fl_Widget *w, void *) { Fl_Text_Editor::kf_select_all(0, editor); }
static void callback_edit_undo(Fl_Widget *w, void *) { Fl_Text_Editor::kf_undo(0, editor); }


//
// Creates the menubar
//
void init_menubar(Fl_Widget *parent) {
    Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, parent->w(), 25);
    
    // The file menu
    menubar->add("&File/&New", 0, callback_file_new);
    menubar->add("&File/&Open", 0, callback_file_open);
    menubar->add("&File/&Save", 0, callback_file_save);
    menubar->add("&File/&Save As", 0, callback_file_save_as);
    menubar->add("&File/&Quit", 0, callback_file_quit);
    
    // The edit menu
    menubar->add("&Edit/&Cut", 0, callback_edit_cut);
    menubar->add("&Edit/&Copy", 0, callback_edit_copy);
    menubar->add("&Edit/&Paste", 0, callback_edit_paste);
    menubar->add("&Edit/&Select All", 0, callback_edit_select_all);
    menubar->add("&Edit/&Undo", 0, callback_edit_undo);
    // The help menu
    menubar->add("&Help/&About", 0, NULL);
}

//
// Creates the editor
//
void init_editor(Fl_Widget *parent) {
    editor = new Fl_Text_Editor(0, 25, parent->w(), (parent->h() - 25));
    Fl_Text_Buffer *buffer = new Fl_Text_Buffer;
    editor->buffer(buffer);
}

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(900, 600, "MiniEdit");
    window->resizable(window);
    
    init_menubar(window);
    init_editor(window);
    
    window->end();
    window->show();
    return Fl::run();
}

