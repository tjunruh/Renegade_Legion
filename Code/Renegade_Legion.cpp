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
    frame* scenario_setup_frame = new frame();
    frame* tank_fleet_setup_display = new frame();
    game_operations game_manager(tank_view_frame, tank_stats_frame, scenario_setup_frame, tank_fleet_setup_display);
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
        ascii_io::zoom_to_level(0);
        home_frame->display();
        int key_stroke = ascii_io::undefined;
        initialization_menu.get_selection(selection, key_stroke);

        if (selection == "View Tanks")
        {
            game_manager.run_tank_view();
        }
        else if (selection == "New Game")
        {
            game_manager.run_new_game_setup();
        }

    } while (selection != "Exit");

    delete(home_frame);
    delete(tank_view_frame);
    delete(tank_stats_frame);
    delete(scenario_setup_frame);
    delete(tank_fleet_setup_display);
    ascii_io::show_cursor();
    ascii_io::ascii_engine_end();
}
