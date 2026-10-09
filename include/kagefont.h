#ifndef _KAGEFONT_H
#define _KAGEFONT_H

#include <vector>

#include "canva.h"
#include "gwdata.h"

namespace Kage {

    typedef enum {
        KAGEFONT_DEFAULT,
        KAGEFONT_MINCHO,
        KAGEFONT_GOTHIC
    } KageFontType;

    class KageFont {
    protected:
        KageFontType _type = KAGEFONT_DEFAULT;
        double       _size;

    public:
        KageFont(double size = 0);
        virtual ~KageFont()                                  = default;
        virtual Canva DrawGlyph(std::vector<Stroke> strokes) = 0;
        // Same as DrawGlyph, but returns one Canva per stroke so that the
        // caller can render / select strokes separately.  The default draws
        // each stroke on its own (no inter-stroke adjustment); fonts whose
        // DrawGlyph adjusts strokes against each other should override it.
        virtual std::vector<Canva> DrawGlyphSeparated(
            std::vector<Stroke> strokes);

        KageFontType GetType();
    };

} // namespace Kage

#endif
