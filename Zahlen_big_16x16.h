/* File generated by pnm2font                          */
/* http://bax.comlab.uni-rostock.de                    */
/*                                                     */

#ifndef PROGMEM
#define PROGMEM
#endif

extern const unsigned char PROGMEM font_image_16_16[320];
extern const Bax_font font_16_16;

#ifdef FONT_MAIN
/* font image width 1330 height 16 */
/* attention: characters in row-by-row order, first    */
/* pixel is MSB of first byte (other implementations   */
/* typically use vertical strips of 8 pixels).         */
#ifdef BAX_FONT
/* verify min/max (first two entries) before use! */
const Bax_font font_16_16 PROGMEM = {
 48,58,28,16,16,font_image_16_16,(0) };
#ifndef DEF_FONT
#define DEF_FONT &font_16_16
#endif /* DEF_FONT */
#else /* BAX_FONT */
#define FONT_STRIDE 32
#define FONT_WIDTH  16
#define FONT_HEIGHT 16
#define FONT_MIN    48
#define FONT_MAX    58
#define FONT_IMAGE  font_image_16_16
#endif
const unsigned char PROGMEM font_image_16_16[320] = {
0x7f, 0xf8, 0x7f, 0xf8, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 
0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x7f, 0xf8, 0x7f, 0xf8, 0x1f, 0x07, 0x1f, 0x07, 0x03, 0x00, 0x03, 0x00, 
0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x07, 0x03, 0x07, 0x03, 0x06, 0x03, 0x06, 0x03, 0x06, 0x03, 0x06, 0x03, 0x06, 
0x03, 0x07, 0x03, 0x07, 0xff, 0x9f, 0xff, 0x9f, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0xff, 0x81, 
0xff, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x9f, 0xff, 0x9f, 0xfe, 0x60, 0xfe, 0x60, 
0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0xfe, 0x60, 0xfe, 0x7f, 0x06, 0x7f, 0x06, 0x00, 0x06, 0x00, 
0x06, 0x00, 0x06, 0x00, 0xfe, 0x00, 0xfe, 0x00, 0x19, 0xff, 0x19, 0xff, 0x19, 0x80, 0x19, 0x80, 0x19, 0x80, 0x19, 0x80, 
0x19, 0x80, 0x19, 0xff, 0xf9, 0xff, 0xf8, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x19, 0xff, 0x19, 0xff, 
0xe7, 0xff, 0xe7, 0xff, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0xe6, 0x00, 0xe7, 0xff, 0x67, 0xff, 
0x66, 0x01, 0x66, 0x01, 0x66, 0x01, 0x66, 0x01, 0xe7, 0xff, 0xe7, 0xff, 0x9f, 0xfe, 0x9f, 0xfe, 0x00, 0x06, 0x00, 0x06, 
0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x80, 0x06, 0x80, 0x06, 0x80, 0x06, 0x80, 0x06, 0x80, 0x06, 0x80, 0x06, 
0x80, 0x06, 0x80, 0x06, 0x7f, 0xf9, 0x7f, 0xf9, 0x60, 0x19, 0x60, 0x19, 0x60, 0x19, 0x60, 0x19, 0x60, 0x19, 0x7f, 0xf9, 
0x7f, 0xf9, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x60, 0x18, 0x7f, 0xf9, 0x7f, 0xf9, 0xff, 0xe0, 0xff, 0xe0, 
0x80, 0x60, 0x80, 0x60, 0x80, 0x60, 0x80, 0x60, 0x80, 0x60, 0xff, 0xe0, 0xff, 0xe0, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 
0x00, 0x60, 0x00, 0x60, 0xff, 0xe0, 0xff, 0xe0, 0xfc, 0x00, 0xfc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xfc, 0x00, 
0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00


};
#endif
