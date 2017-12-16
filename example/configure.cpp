#include "configure.h"

// Game Loop Timing
const int TICKS_PER_SECOND = 30;
const double SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;

// Screen Attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;
const int SCREEN_BPP = 32;

// Boundaries for entity movement

const int TOP_BOUNDARY = 0;
const int LEFT_BOUNDARY = 0;
const int BOTTOM_BOUNDARY = 576;
const int RIGHT_BOUNDARY = 1024;
