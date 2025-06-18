#include <ascii_engine/frame.h>
#include <ascii_engine/file_manager.h>
#include <ascii_engine/label.h>
#include <ascii_engine/menu.h>
#include <ascii_engine/ascii_io.h>
#include "game_operations.h"

int main()
{
    ascii_io::ascii_engine_init(true);
    frame* home_frame = new frame();
    frame* tank_view_frame = new frame();
    frame* tank_stats_frame = new frame();
    game_operations game_manager(tank_view_frame, tank_stats_frame);
    std::string logo_text = "";
    file_manager::read_file("text_images/logo.txt", logo_text);
    label logo(home_frame);
    logo.set_alignment("center block");
    logo.enable_word_wrap(false);
    logo.set_output(logo_text);
    logo.set_spacing(6, 6, 0, 0);
    menu initialization_menu(home_frame, "new line");
    initialization_menu.set_alignment("center block");
    initialization_menu.append_item("New Game");
    initialization_menu.append_item("Load Game");
    initialization_menu.append_item("View Tanks");
    initialization_menu.append_item("Exit");
    initialization_menu.build();

    ascii_io::hide_cursor();
    std::string selection = "";
    do
    {
        home_frame->display();
        int key_stroke = ascii_io::undefined;
        initialization_menu.get_selection(selection, key_stroke);

        if (selection == "View Tanks")
        {
            game_manager.run_tank_view();
        }

    } while (selection != "Exit");

    delete(home_frame);
    ascii_io::show_cursor();
    ascii_io::ascii_engine_end();
}
