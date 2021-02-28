/* Main TUI for SMDGB.
 * Author: Biel A. P. <0xbiel>
 * License: GPL v3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

WINDOW *createWin(WINDOW *window)
{
  int x, y, i;
  getmaxyx(window, y, x);
  box(window, 0, 0);
}

int main()
{
  int px, py, nx, ny;
  int inputSize = 3;

  initscr();
  //curs_set(FALSE);
  //noecho();

  getmaxyx(stdscr, py, px);
  WINDOW *dbg = newwin(py - inputSize, px, 0, 0);
  WINDOW *input = newwin(inputSize, px, py - inputSize, 0);

  createWin(dbg);
  createWin(input);

  while(1)
  {
    getmaxyx(stdscr, ny, nx);

    if(ny != py || nx != px)
    {
      px = nx;
      py = ny;
      wresize(dbg, ny - inputSize, nx);
      wresize(input, inputSize, nx);
      mvwin(input, ny - inputSize, 0);
      wclear(stdscr);
      wclear(dbg);
      wclear(input);
      createWin(dbg);
      createWin(input);
    }

    mvwprintw(dbg, 1, 1, "Placeholder 0xsmdbg.");
    mvwscanw(input, 1, 1, "");
    wrefresh(dbg);
    wrefresh(input);
  }

  endwin();

  return 0;
}
