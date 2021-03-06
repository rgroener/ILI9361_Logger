/* File generated by pnm2font                          */
/* http://bax.comlab.uni-rostock.de                    */
/*                                                     */

#ifndef PROGMEM
#define PROGMEM
#endif

extern const unsigned char PROGMEM font_image_9_17[1700];
extern const Bax_font font_9_17;

#ifdef FONT_MAIN
/* font image width 760 height 17 */
/* attention: characters in row-by-row order, first    */
/* pixel is MSB of first byte (other implementations   */
/* typically use vertical strips of 8 pixels).         */
#ifdef BAX_FONT
/* verify min/max (first two entries) before use! */
const Bax_font font_9_17 PROGMEM = {
 32,126,20,9,17,font_image_9_17,(0) };
#ifndef DEF_FONT
#define DEF_FONT &font_9_17
#endif /* DEF_FONT */
#else /* BAX_FONT */
#define FONT_STRIDE 20	//(FONT_WITH x FONT_HEIGHT) + aufrunden auf nächste Zahl durch 8 teilbar
#define FONT_WIDTH  9
#define FONT_HEIGHT 17
#define FONT_MIN    32
#define FONT_MAX    126
#define FONT_IMAGE  font_image_9_17
#endif
const unsigned char PROGMEM font_image_9_17[1700] = {	
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x01, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x02, 0x81, 0x40, 0xa0, 0x51, 0x80, 0x40, 0x20, 0x70, 0x08, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x02, 0x41, 0x23, 0xb2, 0x7d, 0x08, 0xc4, 0x3f, 0x02, 0x01, 0x08, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 
0x0c, 0xe9, 0x4c, 0xa1, 0x90, 0x1e, 0x35, 0xa2, 0x43, 0x21, 0xe0, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
0x82, 0x01, 0x08, 0xc8, 0x60, 0x4b, 0x22, 0x51, 0x2c, 0x63, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
0x80, 0x40, 0x20, 0x01, 0x00, 0x80, 0x40, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x80, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x01, 0x00, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x02, 0x01, 0x00, 0x40, 
0x20, 0x10, 0x08, 0x04, 0x02, 0x02, 0x01, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x91, 0xf0, 0x70, 
0xd6, 0x08, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x10, 
0x3f, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x18, 0x03, 0x01, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
0x00, 0x00, 0x03, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 
0x04, 0x04, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x82, 0x22, 0x01, 0x00, 0x90, 0x40, 0x20, 0x10, 
0x04, 0x41, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x88, 0x44, 0x22, 0x11, 0x08, 0x84, 0x42, 0x01, 
0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc4, 0x30, 0x08, 0x04, 0x04, 0x06, 0x06, 0x04, 0x04, 0x07, 
0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc4, 0x10, 0x08, 0x0c, 0x38, 0x03, 0x40, 0xa0, 0x48, 0x63, 0xe0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xa4, 0xd2, 0x49, 0xc4, 0x82, 0x1f, 0x80, 0x80, 0x48, 0x22, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc2, 0x03, 0x03, 0x71, 0x04, 0xa1, 0x60, 0xa0, 0x50, 0x45, 0xc1, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xcf, 0x10, 0x00, 0x00, 0x1c, 0x03, 0x08, 0x84, 0x44, 0x62, 0xe2, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0xb4, 0x12, 0x11, 0x08, 0x78, 0x60, 0x20, 0x10, 0x0c, 0x03, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x47, 0x96, 0x2a, 0x05, 0x04, 0xc7, 0x3c, 0x80, 0x40, 0xe8, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x62, 0x31, 0x00, 0x80, 0x40, 0x03, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x30, 0x00, 0x00, 0x00, 0x03, 0x01, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x08, 0x39, 0x70, 0x40, 0x1c, 0x23, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x02, 0xfc, 0x80, 0x00, 0x1f, 0x80, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x06, 0x04, 0x00, 0x60, 0x1c, 0x21, 0x17, 0x0e, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 
0x43, 0x21, 0x31, 0x10, 0x90, 0x48, 0x24, 0x12, 0x08, 0x02, 0x01, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x31, 
0x48, 0xbc, 0x52, 0x29, 0x20, 0x9e, 0x48, 0xe8, 0x04, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc4, 0x02, 
0x01, 0x00, 0xfe, 0x43, 0x20, 0x90, 0x28, 0x57, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xd2, 0x1a, 0x05, 
0x00, 0x81, 0x40, 0xa0, 0x50, 0x24, 0x21, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x84, 0x22, 0x09, 0x04, 
0x82, 0x41, 0x20, 0x90, 0x48, 0x47, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xec, 0x06, 0x03, 0x01, 0xfe, 
0xc0, 0x60, 0x30, 0x18, 0x0f, 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x02, 0x02, 0x01, 0x7e, 0x80, 
0x40, 0x20, 0x10, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc8, 0x14, 0x02, 0x01, 0x00, 0xe3, 0x40, 
0xa0, 0x50, 0x29, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x10, 0x88, 0x44, 0x3e, 0x11, 0x08, 0x84, 
0x42, 0x21, 0x13, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x08, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x64, 0x52, 0x49, 0x44, 0xe2, 0x49, 0x26, 0x91, 0x48, 
0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x17, 
0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x66, 0x32, 0xa9, 0x54, 0xaa, 0x49, 0x20, 0x90, 0x48, 0x24, 0x10, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x26, 0x12, 0x8b, 0x45, 0x92, 0xc9, 0x62, 0xb1, 0x58, 0x64, 0x30, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x8e, 0x24, 0x0a, 0x05, 0x02, 0x81, 0x60, 0xa0, 0x54, 0x49, 0xc4, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc2, 0x32, 0x0a, 0x05, 0x06, 0x9e, 0x40, 0x20, 0x10, 0x04, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x8f, 0x24, 0x0a, 0x05, 0x02, 0x81, 0x78, 0xa0, 0x50, 0x48, 0xe4, 0x30, 0x08, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xc3, 0xb6, 0x0a, 0x05, 0x06, 0x64, 0x0d, 0x00, 0x40, 0x28, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x4f, 0xd0, 0x80, 0x40, 0x20, 0x12, 0x08, 0x84, 0x42, 0x61, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x28, 0x24, 0x12, 0x09, 0x04, 0x82, 0x41, 0x20, 0x90, 0x4c, 0x63, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x08, 0x34, 0x19, 0x14, 0x8a, 0x44, 0x14, 0x0a, 0x05, 0x02, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x28, 0x10, 0x08, 0x64, 0xb4, 0x5a, 0x2d, 0x09, 0x04, 0x82, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x2a, 0x22, 0xa1, 0x50, 0x10, 0x14, 0x0a, 0x08, 0x84, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 
0x20, 0x10, 0x50, 0x38, 0x08, 0x04, 0x0a, 0x09, 0x0c, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe2, 0x31, 
0x10, 0x90, 0x50, 0x28, 0x10, 0x08, 0x04, 0x02, 0xf1, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0x02, 0x01, 
0x00, 0x80, 0x20, 0x10, 0x04, 0x02, 0x00, 0x80, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x01, 0x00, 0x80, 0x40, 
0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x81, 0xc8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x41, 0x11, 0x8c, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x18, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x04, 0xe3, 0x89, 0x84, 0xbe, 0x41, 
0x20, 0x90, 0xcf, 0xa4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x84, 0x82, 0x41, 0x20, 
0x90, 0x85, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0xc8, 0x80, 0x80, 0x40, 0x20, 0x10, 
0x44, 0xc3, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x31, 0xf8, 0x94, 0x82, 0x7d, 0x20, 0x90, 0xc4, 
0x21, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x82, 0x01, 0x03, 0xf8, 0x44, 0x22, 0x10, 0x08, 0x04, 0x42, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xd0, 0x98, 0x84, 0x42, 0x21, 0x10, 0x84, 0xc3, 0xa0, 
0x10, 0x88, 0x38, 0x00, 0x00, 0x00, 0x10, 0x08, 0x04, 0x02, 0xe1, 0x88, 0x84, 0x42, 0x21, 0x10, 0x88, 0x44, 0x20, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x01, 0xc0, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x07, 0xf0, 0x00, 0x00, 
0x00, 0x80, 0x00, 0x00, 0x02, 0x11, 0x08, 0x05, 0xc2, 0x21, 0x10, 0x88, 0x64, 0x22, 0x11, 0x08, 0x84, 0x40, 0x20, 0x60, 
0x00, 0x00, 0x00, 0x00, 0x3c, 0x02, 0x01, 0x20, 0xa0, 0x60, 0x30, 0x14, 0x0a, 0x04, 0x82, 0x20, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc1, 0x20, 0x90, 0x48, 0x24, 0x12, 0x09, 0xe4, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0xe5, 0x82, 0x81, 0x40, 0xa0, 0x50, 0x28, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0xe9, 0x9c, 0x86, 0x43, 0x21, 0x90, 0xcc, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x02, 0xe1, 0x90, 0x84, 0x42, 0x21, 0x10, 0x8c, 0x87, 0xc2, 0x01, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x01, 0xd0, 0x98, 0x84, 0x42, 0x21, 0x10, 0x84, 0xc3, 0xa0, 0x10, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0xe0, 0xc9, 0x40, 0xa0, 0x50, 0x08, 0x04, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x01, 0xe3, 0x08, 0x00, 0x30, 0x07, 0x00, 0x80, 0x43, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 
0xf2, 0x41, 0x20, 0x90, 0x48, 0x24, 0x12, 0x08, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 
0x09, 0x04, 0x42, 0x21, 0x10, 0x86, 0xc3, 0xa1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x0a, 
0x08, 0xb4, 0x5a, 0x2c, 0x16, 0x04, 0x82, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x14, 0x94, 
0x32, 0x19, 0x0c, 0x89, 0x04, 0x84, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x88, 0x48, 
0x24, 0x0a, 0x06, 0x01, 0x00, 0x80, 0x40, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x08, 0x08, 0x08, 
0x08, 0x08, 0x08, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x00, 0x80, 0x40, 0x20, 0x10, 0x30, 0x04, 
0x02, 0x01, 0x00, 0x80, 0x40, 0x18, 0x00, 0x00, 0x00, 0x00, 0x02, 0x09, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 
0x01, 0x00, 0x80, 0x40, 0x20, 0x90, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x80, 0x40, 0x20, 0x10, 0x06, 0x34, 0x22, 0x01, 
0x00, 0x80, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x03, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00





};
#endif
