#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>

#include <curses.h>

using namespace std::chrono_literals;

int main()
{
    // Create a screen with full width and height fitting the document.
    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(), // Width
        ftxui::Dimension::Full()  // Height
    );

    float progress1 = 0.0f;
    float progress2 = 0.0f;
    while (progress1 < 1.0f || progress2 < 1.0f)
    {
        progress1 += 0.01f;
        progress2 += 0.02f;

        auto document = ftxui::vbox({
                            ftxui::hbox(
                                ftxui::gauge(progress1) | ftxui::border | ftxui::flex | ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 50)),
                            ftxui::hbox(
                                ftxui::gauge(progress2) | ftxui::border | ftxui::flex |
                                ftxui::size(ftxui::WIDTH, ftxui::GREATER_THAN, 50)),
                        }) |
                        ftxui::center;

        ftxui::Render(screen, document);
        screen.Print();
        std::this_thread::sleep_for(10ms);
        std::cout << screen.ResetPosition(true);
    }
}
