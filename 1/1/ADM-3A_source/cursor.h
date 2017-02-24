#ifndef _CURSOR_
#define _CURSOR_

#define clear() printf("\033[H\033[J");
#define move(r, c) printf("\033[%d;%dH", (r), (c));

#endif
