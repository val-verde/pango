#ifndef __THAI_SHAPER_H__
#define __THAI_SHAPER_H__

#include "pangox.h"

#define ucs2tis(wc)     (unsigned int)((unsigned int)(wc) - 0x0E00 + 0xA0)
#define tis2uni(c)      ((gunichar)(c) - 0xA0 + 0x0E00)

typedef struct _ThaiFontInfo ThaiFontInfo;

/* Font encodings we will use
 */
typedef enum {
  THAI_FONT_NONE,
  THAI_FONT_XTIS,
  THAI_FONT_TIS,
  THAI_FONT_TIS_MAC,
  THAI_FONT_TIS_WIN,
  THAI_FONT_ISO10646
} ThaiFontSet;

typedef enum {
  THAI_FONTINFO_X,
  THAI_FONTINFO_XFT
} ThaiFontInfoType;

struct _ThaiFontInfo
{
  PangoFont       *font;
  ThaiFontSet      font_set;
  PangoXSubfont    subfont; /* For X backend */
};

/*
 * Abstract methods (implemented by each shaper module)
 */
ThaiFontInfo *
thai_get_font_info (PangoFont *font);

PangoGlyph
thai_make_glyph (ThaiFontInfo *font_info, unsigned int c);

PangoGlyph
thai_make_unknown_glyph (ThaiFontInfo *font_info, unsigned int c);

gboolean
thai_has_glyph (ThaiFontInfo *font_info, PangoGlyph glyph);

/*
 * Public functions
 */
void
thai_engine_shape (PangoFont        *font,
                   const char       *text,
                   gint              length,
                   PangoAnalysis    *analysis,
                   PangoGlyphString *glyphs);

#endif /* __THAI_SHAPER_H__ */

