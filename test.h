/* File generated by pnm2font                          */
/* http://bax.comlab.uni-rostock.de                    */
/*                                                     */

#ifndef PROGMEM
#define PROGMEM
#endif

extern const unsigned char PROGMEM font_image_8_16[2375];
extern const Bax_font font_8_16;

#ifdef FONT_MAIN
/* font image width 760 height 16 */
/* attention: characters in row-by-row order, first    */
/* pixel is MSB of first byte (other implementations   */
/* typically use vertical strips of 8 pixels).         */
#ifdef BAX_FONT
/* verify min/max (first two entries) before use! */
const Bax_font font_8_16 PROGMEM = {
 32,126,25,13,15,font_image_8_16,(0) };
#ifndef DEF_FONT
#define DEF_FONT &font_8_16
#endif /* DEF_FONT */
#else /* BAX_FONT */
#define FONT_STRIDE 25
#define FONT_WIDTH  13
#define FONT_HEIGHT 15
#define FONT_MIN    32
#define FONT_MAX    126
#define FONT_IMAGE  font_image_8_16
#endif
const unsigned char PROGMEM font_image_8_16[2375] = {

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0x80, 0x04, 0x00, 0x60, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x03, 0xc0, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 0xf0, 0x1f, 0x80, 0xc4, 0x07, 0x00, 0x1e, 0x00, 0x38, 0x08, 0xc0, 0x7e, 0x03, 0xe0, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x7c, 0x03, 0x80, 0x0e, 0x00, 0xf8, 0x0c, 0xc0, 0x63, 0x03, 0xfc, 0x0f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x03, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x78, 0x03, 0x80, 0x3c, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xc0, 0x02, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x06, 0x00, 0x20, 0x01, 0x00, 0x08, 0x00, 0x40, 0x06, 0x00, 0x20, 0x01, 0x00, 0x08, 0x00, 0x40, 0x06, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0xf8, 0x0e, 0x40, 0x63, 0x07, 0x18, 0x38, 0xc0, 0xec, 0x07, 0xe0, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x1c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0xe0, 0x33, 0x00, 0x18, 0x01, 0xc0, 0x1c, 0x01, 0xc0, 0x1f, 0xc0, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0xfe, 0x06, 0x60, 0x0e, 0x00, 0x78, 0x00, 0xe0, 0x03, 0x03, 0x38, 0x1f, 0x80, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x1c, 0x01, 0xe0, 0x1b, 0x00, 0xd8, 0x0f, 0xe0, 0x7f, 0x00, 0x30, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x03, 0xf0, 0x18, 0x00, 0xf8, 0x07, 0xe0, 0x03, 0x01, 0x18, 0x0f, 0xc0, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x1c, 0x01, 0x80, 0x1f, 0x00, 0xfc, 0x06, 0x60, 0x33, 0x01, 0xf8, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x1f, 0xc0, 0x0c, 0x00, 0x60, 0x07, 0x00, 0x30, 0x01, 0x80, 0x18, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x01, 0xfc, 0x0c, 0x60, 0x3e, 0x01, 0xf8, 0x18, 0xc0, 0xc6, 0x07, 0xf0, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x3f, 0x81, 0xcc, 0x0e, 0x60, 0x7f, 0x00, 0xf0, 0x03, 0x00, 0x38, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x06, 0x00, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x07, 0xc0, 0x66, 0x00, 0x30, 0x07, 0x00, 0x30, 0x01, 0x80, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0e, 0x00, 0x70, 0x06, 0xc0, 0x36, 0x01, 0xb0, 0x1f, 0x80, 0xfe, 0x06, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0xfe, 0x06, 0x30, 0x31, 0x81, 0xf8, 0x0f, 0xc0, 0x63, 0x03, 0x18, 0x1f, 0xc1, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x7e, 0x07, 0x00, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x1f, 0x80, 0xce, 0x06, 0x30, 0x31, 0x81, 0x8c, 0x0c, 0xe0, 0x7e, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x03, 0xf8, 0x18, 0x00, 0xfc, 0x07, 0xe0, 0x30, 0x01, 0x80, 0x0f, 0xc0, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x7f, 0x03, 0x00, 0x18, 0x00, 0xfc, 0x07, 0xe0, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x07, 0xe0, 0x71, 0x03, 0x00, 0x19, 0xc0, 0xce, 0x06, 0x30, 0x1f, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x81, 0x8c, 0x0c, 0x60, 0x7f, 0x03, 0xf8, 0x18, 0xc0, 0xc6, 0x06, 0x30, 0x31, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x0f, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x80, 0xcc, 0x06, 0xc0, 0x3c, 0x01, 0xe0, 0x0f, 0x80, 0x6c, 0x03, 0x70, 0x19, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x7e, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0x07, 0x18, 0x39, 0xc1, 0xee, 0x0f, 0xf0, 0x7f, 0x83, 0x6c, 0x1b, 0x60, 0xd3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x73, 0x03, 0xd8, 0x1e, 0xc0, 0xfe, 0x06, 0xf0, 0x37, 0x81, 0x9c, 0x0c, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0xe0, 0x73, 0x83, 0x0c, 0x18, 0x60, 0xc7, 0x06, 0x30, 0x3f, 0x80, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x01, 0xfc, 0x0c, 0xe0, 0x63, 0x03, 0x18, 0x1f, 0x80, 0xf0, 0x06, 0x00, 0x70, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x1f, 0x81, 0xce, 0x0c, 0x30, 0x61, 0x83, 0x3c, 0x1b, 0xc0, 0xfe, 0x03, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0xf0, 0x31, 0x81, 0x8c, 0x0f, 0xc0, 0x7c, 0x03, 0x60, 0x39, 0x81, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0xfc, 0x06, 0x20, 0x38, 0x00, 0xf0, 0x01, 0xc0, 0x46, 0x03, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x1f, 0xc0, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x03, 0x18, 0x18, 0xc0, 0xc6, 0x06, 0x30, 0x31, 0x81, 0x8c, 0x0f, 0xc0, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x60, 0x63, 0x03, 0x30, 0x19, 0x80, 0xec, 0x03, 0xc0, 0x1e, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x66, 0x1b, 0x30, 0xdf, 0x07, 0xf8, 0x3f, 0xc1, 0xfe, 0x0e, 0x70, 0x73, 0x83, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x01, 0xd8, 0x07, 0xc0, 0x1c, 0x00, 0xe0, 0x0f, 0x00, 0xfc, 0x06, 0x60, 0x31, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x30, 0x3b, 0x00, 0xd8, 0x07, 0x80, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0xf0, 0x03, 0x00, 0x30, 0x03, 0x80, 0x38, 0x03, 0x80, 0x1f, 0xc0, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x30, 0x00, 0x80, 0x04, 0x00, 0x20, 0x01, 0x00, 0x0c, 0x00, 0x20, 0x01, 0x00, 0x08, 0x00, 0x40, 0x03, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0e, 0x00, 0x70, 0x06, 0xc0, 0x36, 0x01, 0xb0, 0x1f, 0x80, 0xfe, 0x06, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0xfe, 0x06, 0x30, 0x31, 0x81, 0xf8, 0x0f, 0xc0, 0x63, 0x03, 0x18, 0x1f, 0xc1, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x7e, 0x07, 0x00, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x1f, 0x80, 0xce, 0x06, 0x30, 0x31, 0x81, 0x8c, 0x0c, 0xe0, 0x7e, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x03, 0xf8, 0x18, 0x00, 0xfc, 0x07, 0xe0, 0x30, 0x01, 0x80, 0x0f, 0xc0, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x7f, 0x03, 0x00, 0x18, 0x00, 0xfc, 0x07, 0xe0, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x07, 0xe0, 0x71, 0x03, 0x00, 0x19, 0xc0, 0xce, 0x06, 0x30, 0x1f, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x81, 0x8c, 0x0c, 0x60, 0x7f, 0x03, 0xf8, 0x18, 0xc0, 0xc6, 0x06, 0x30, 0x31, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x0f, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x80, 0xcc, 0x06, 0xc0, 0x3c, 0x01, 0xe0, 0x0f, 0x80, 0x6c, 0x03, 0x70, 0x19, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x7e, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0x07, 0x18, 0x39, 0xc1, 0xee, 0x0f, 0xf0, 0x7f, 0x83, 0x6c, 0x1b, 0x60, 0xd3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x73, 0x03, 0xd8, 0x1e, 0xc0, 0xfe, 0x06, 0xf0, 0x37, 0x81, 0x9c, 0x0c, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0xe0, 0x73, 0x83, 0x0c, 0x18, 0x60, 0xc7, 0x06, 0x30, 0x3f, 0x80, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x01, 0xfc, 0x0c, 0xe0, 0x63, 0x03, 0x18, 0x1f, 0x80, 0xf0, 0x06, 0x00, 0x70, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x1f, 0x81, 0xce, 0x0c, 0x30, 0x61, 0x83, 0x3c, 0x1b, 0xc0, 0xfe, 0x03, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0xf0, 0x31, 0x81, 0x8c, 0x0f, 0xc0, 0x7c, 0x03, 0x60, 0x39, 0x81, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0xfc, 0x06, 0x20, 0x38, 0x00, 0xf0, 0x01, 0xc0, 0x46, 0x03, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x1f, 0xc0, 0x30, 0x01, 0x80, 0x0c, 0x00, 0x60, 0x03, 0x00, 0x18, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x03, 0x18, 0x18, 0xc0, 0xc6, 0x06, 0x30, 0x31, 0x81, 0x8c, 0x0f, 0xc0, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x60, 0x63, 0x03, 0x30, 0x19, 0x80, 0xec, 0x03, 0xc0, 0x1e, 0x00, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x66, 0x1b, 0x30, 0xdf, 0x07, 0xf8, 0x3f, 0xc1, 0xfe, 0x0e, 0x70, 0x73, 0x83, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x01, 0xd8, 0x07, 0xc0, 0x1c, 0x00, 0xe0, 0x0f, 0x00, 0xfc, 0x06, 0x60, 0x31, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x30, 0x3b, 0x00, 0xd8, 0x07, 0x80, 0x18, 0x00, 0xc0, 0x06, 0x00, 0x30, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x07, 0xf0, 0x03, 0x00, 0x30, 0x03, 0x80, 0x38, 0x03, 0x80, 0x1f, 0xc0, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x01, 0xc0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	
	
	
};
#endif
