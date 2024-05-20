//
// Created by luck3 on 5/19/2024.
//

#include "Settings.h"

#include <iostream>
#include <fstream>

std::string Settings::title = {};
int Settings::screen_width = 0;
int Settings::screen_height = 0;

void Settings::load() {
    std::ifstream input_file("./Settings.txt");

    if(!input_file.is_open()) {
        std::cerr << "Error opening settings file!\n";
        return;
    }

    std::string line;
    for(int i=0;i < NUM_SETTINGS_LINES; i++) {
        std::getline(input_file,line);

        switch (i) {
            case 0:
                title = line;
                break;
            case 1:
                screen_width = std::stoi(line);
                break;
            case 2:
                screen_height = std::stoi(line);
            case 4:
                frame_delay = std::stoi(line);
            default:
                break;
        }
    }
}