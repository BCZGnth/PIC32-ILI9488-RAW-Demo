#include "ili9488_shapes.h"
#include "ili9488.h"
#include "system.h"
#include "logger.h"
#include <string.h>
/**
 * Takes a start x,y coordinate and a length of pixels to draw a line
 */
void ili9488_draw_vline(Ili9488Defines screen, Ili9488HVLine Line)
{

    ADD_TO_STACK_DEPTH();
    level_log(TRACE, "ILI9488 Draw VLine");

    uint8_t byte_of_color = (Line.color & 0x7);
    byte_of_color |= ((Line.color << 3) & 0x7);
    uint8_t del_x, del_y;

    Ili9488RamPointer line_ptr = {
        .start_x = Line.xstart,
        .end_x   = Line.xstart + Line.weight - 1,
        .start_y = Line.ystart,
        .end_y   = Line.ystart + Line.length - 1
    };

    del_x = (line_ptr.end_x - line_ptr.start_x);
    del_y = (line_ptr.end_y - line_ptr.start_y);

    uint24_t no_of_pixels =  del_x * del_y;

    no_of_pixels = no_of_pixels + (no_of_pixels % 2); // Evening the no_of_numbers variable
    uint24_t no_of_bytes = no_of_pixels / (uint24_t)2;

    // Use the full buffer size for drawing the line
    /* We will also assume that the Screen.buffer_size is greater than 1 */

    // Calculate the number of full iterations needed
    uint24_t iterations = no_of_bytes / (uint24_t)screen.Screen.buffer_size;
    uint24_t remainder  = no_of_bytes % (uint24_t)screen.Screen.buffer_size;

    ili9488_set_ram_pointer(screen.interface, line_ptr);

    // Only memset as many bytes as needed. 
    if(!iterations) {
        memset(screen.Screen.pbuffer, byte_of_color, remainder);
        ili9488_gram_write(screen.interface, screen.Screen.pbuffer, remainder);

    } else {
        memset(screen.Screen.pbuffer, byte_of_color, screen.Screen.buffer_size);
        
        ili9488_gram_write(screen.interface, screen.Screen.pbuffer, screen.Screen.buffer_size);
        /* This for loop only works because the first "iteration" is completed with a seperate function before the for loop
        * Otherwise, a ""> 0" in a loop will usually be one iteration short of whatever the variable's original value was.
        * This is also only useful if you will not use the value again, which applies in this case.
        * */
       for(; iterations > 0; iterations--) {
           ili9488_gram_write_continue(screen.interface, screen.Screen.pbuffer, screen.Screen.buffer_size);
        }
        
        /* Write the remainder */
        ili9488_gram_write(screen.interface, screen.Screen.pbuffer, remainder);
    }


    level_log(TRACE, "Ili9488 Drew VLine");
    REMOVE_FROM_STACK_DEPTH();
}

void ili9488_draw_hline(Ili9488Defines screen, Ili9488HVLine Line)
{

    ADD_TO_STACK_DEPTH();
    level_log(TRACE, "ILI9488 Draw VLine");

    uint8_t byte_of_color = (Line.color & 0x7);
    byte_of_color |= ((Line.color << 3) & 0x7);
    uint8_t del_x, del_y;

    Ili9488RamPointer line_ptr = {
        .start_x = Line.xstart,
        .end_x   = Line.xstart + Line.length - 1,
        .start_y = Line.ystart,
        .end_y   = Line.ystart + Line.weight - 1
    };

    del_x = (line_ptr.end_x - line_ptr.start_x);
    del_y = (line_ptr.end_y - line_ptr.start_y);

    uint24_t no_of_pixels =  del_x * del_y;

    no_of_pixels = no_of_pixels + (no_of_pixels % 2); // Evening the no_of_numbers variable
    uint24_t no_of_bytes = no_of_pixels / (uint24_t)2;

    // Use the full buffer size for drawing the line
    /* We will also assume that the Screen.buffer_size is greater than 1 */

    // Calculate the number of full iterations needed
    uint24_t iterations = no_of_bytes / (uint24_t)screen.Screen.buffer_size;
    uint24_t remainder  = no_of_bytes % (uint24_t)screen.Screen.buffer_size;

    ili9488_set_ram_pointer(screen.interface, line_ptr);
    
    // Only memset as many bytes as needed. 
    if(!iterations) {
        memset(screen.Screen.pbuffer, byte_of_color, remainder);
        ili9488_gram_write(screen.interface, screen.Screen.pbuffer, remainder);

    } else {
        memset(screen.Screen.pbuffer, byte_of_color, screen.Screen.buffer_size);
        
        ili9488_gram_write(screen.interface, screen.Screen.pbuffer, screen.Screen.buffer_size);
        /* This for loop only works because the first "iteration" is completed with a seperate function before the for loop
        * Otherwise, a ""> 0" in a loop will usually be one iteration short of whatever the variable's original value was.
        * This is also only useful if you will not use the value again, which applies in this case.
        * */
       for(; iterations > 0; iterations--) {
           ili9488_gram_write_continue(screen.interface, screen.Screen.pbuffer, screen.Screen.buffer_size);
        }
        
        /* Write the remainder */
        ili9488_gram_write(screen.interface, screen.Screen.pbuffer, remainder);
    }

    level_log(TRACE, "Ili9488 Drew VLine");
    REMOVE_FROM_STACK_DEPTH();
}

void ili9488_draw_rect(Ili9488Defines screen, Ili9488Rect Rect){
    // ili9488_send_command(screen, SET_DISPLAY_ON_OUTPUT_IGNORES_RAM_CONTENT);
    ADD_TO_STACK_DEPTH();
    level_log(TRACE, "Ili9488 Draw Rectangle");

    uint8_t hlength = (Rect.xend - Rect.xstart + 1);
    // uint8_t hxstart = Rect.xstart + Rect.weight;
    uint8_t vlength = (Rect.yend - Rect.ystart + 1);

    Ili9488HVLine hline1 = {
        .xstart = Rect.xstart,
        .ystart = Rect.ystart,
        .length = hlength,
        .weight = Rect.weight,
        .color  = Rect.color
    };

    Ili9488HVLine vline1 = {
        .xstart = Rect.xstart,
        .ystart = Rect.ystart,
        .length = vlength,
        .weight = Rect.weight,
        .color  = Rect.color
    };

    Ili9488HVLine hline2 = {
        .xstart = Rect.xstart,
        .ystart = Rect.yend,
        .length = hlength,
        .weight = Rect.weight,
        .color  = Rect.color
    };

    Ili9488HVLine vline2 = {
        .xstart = Rect.xend,
        .ystart = Rect.ystart,
        .length = vlength,
        .weight = Rect.weight,
        .color  = Rect.color
    };

    ili9488_draw_hline(screen, hline1);
    ili9488_draw_vline(screen, vline1);
    ili9488_draw_hline(screen, hline2);
    ili9488_draw_vline(screen, vline2);

    // ili9488_send_command(screen, SET_DISPLAY_ON_RESUME_RAM_CONTENT_DISPLAY);
    level_log(TRACE, "ILI9488 Drew Rectangle");
    REMOVE_FROM_STACK_DEPTH();
}

