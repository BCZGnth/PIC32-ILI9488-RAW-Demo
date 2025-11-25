// -----------------------------------------------------------------------------
// ILI9488 Standard DCS Command Set (0x00–0x5F)
// -----------------------------------------------------------------------------

#define ILI9488_NOP                          0x00
#define ILI9488_SOFTWARE_RESET               0x01

#define ILI9488_READ_DISPLAY_ID              0x04
#define ILI9488_READ_NUMBER_OF_ERRORS        0x05
#define ILI9488_READ_DISPLAY_STATUS          0x09
#define ILI9488_READ_DISPLAY_POWER_MODE      0x0A
#define ILI9488_READ_DISPLAY_MADCTL          0x0B
#define ILI9488_READ_DISPLAY_PIXEL_FORMAT    0x0C
#define ILI9488_READ_DISPLAY_IMAGE_MODE      0x0D
#define ILI9488_READ_DISPLAY_SIGNAL_MODE     0x0E
#define ILI9488_READ_SELF_DIAGNOSTIC         0x0F

#define ILI9488_SLEEP_IN                     0x10
#define ILI9488_SLEEP_OUT                    0x11
#define ILI9488_PARTIAL_MODE_ON              0x12
#define ILI9488_NORMAL_DISPLAY_MODE_ON       0x13

#define ILI9488_DISPLAY_INVERSION_OFF        0x20
#define ILI9488_DISPLAY_INVERSION_ON         0x21

// Added from screenshot 3:
#define ILI9488_ALL_PIXELS_OFF               0x22
#define ILI9488_ALL_PIXELS_ON                0x23

#define ILI9488_DISPLAY_OFF                  0x28
#define ILI9488_DISPLAY_ON                   0x29

#define ILI9488_COLUMN_ADDRESS_SET           0x2A
#define ILI9488_PAGE_ADDRESS_SET             0x2B
#define ILI9488_MEMORY_WRITE                 0x2C
#define ILI9488_COLOR_SET                    0x2D
#define ILI9488_MEMORY_READ                  0x2E

#define ILI9488_PARTIAL_AREA                 0x30
#define ILI9488_VERTICAL_SCROLL_DEFINITION   0x33

#define ILI9488_TEARING_EFFECT_LINE_OFF      0x34
#define ILI9488_TEARING_EFFECT_LINE_ON       0x35

#define ILI9488_MEMORY_ACCESS_CONTROL        0x36
#define ILI9488_VERTICAL_SCROLL_START_ADDR   0x37
#define ILI9488_IDLE_MODE_OFF                0x38
#define ILI9488_IDLE_MODE_ON                 0x39
#define ILI9488_INTERFACE_PIXEL_FORMAT       0x3A
#define ILI9488_MEMORY_WRITE_CONTINUE        0x3C
#define ILI9488_MEMORY_READ_CONTINUE         0x3E

#define ILI9488_WRITE_TEAR_SCANLINE          0x44
#define ILI9488_READ_SCANLINE                0x45

#define ILI9488_WRITE_DISPLAY_BRIGHTNESS     0x51
#define ILI9488_READ_DISPLAY_BRIGHTNESS      0x52
#define ILI9488_WRITE_CONTROL_DISPLAY        0x53
#define ILI9488_READ_CONTROL_DISPLAY         0x54
#define ILI9488_WRITE_CABC                   0x55
#define ILI9488_READ_CABC                    0x56

#define ILI9488_WRITE_CABC_MIN_BRIGHTNESS    0x5E
#define ILI9488_READ_CABC_MIN_BRIGHTNESS     0x5F

// Screenshot 1 extra:
#define ILI9488_READ_AUTOMATIC_BRIGHTNESS    0x68

// ID register reads
#define ILI9488_READ_ID1                     0xDA
#define ILI9488_READ_ID2                     0xDB
#define ILI9488_READ_ID3                     0xDC

// -----------------------------------------------------------------------------
// ILI9488 Extended Command Set (0xB0–0xFF)
// (From screenshots 1 & 2: sections 5.3.x, pages ~219–278)
// -----------------------------------------------------------------------------

#define ILI9488_INTERFACE_MODE_CONTROL       0xB0
#define ILI9488_FRAME_RATE_CONTROL_NORMAL    0xB1
#define ILI9488_FRAME_RATE_CONTROL_IDLE      0xB2
#define ILI9488_FRAME_RATE_CONTROL_PARTIAL   0xB3
#define ILI9488_DISPLAY_INVERSION_CONTROL    0xB4
#define ILI9488_BLANKING_PORCH_CONTROL       0xB5
#define ILI9488_DISPLAY_FUNCTION_CONTROL     0xB6
#define ILI9488_ENTRY_MODE_SET               0xB7
#define ILI9488_COLOR_ENHANCEMENT_1          0xB9
#define ILI9488_COLOR_ENHANCEMENT_2          0xBA
#define ILI9488_HS_LANES_CONTROL             0xBE

// Power control (screenshot 2)
#define ILI9488_POWER_CONTROL_1              0xC0
#define ILI9488_POWER_CONTROL_2              0xC1
#define ILI9488_POWER_CONTROL_3              0xC2
#define ILI9488_POWER_CONTROL_4              0xC3
#define ILI9488_POWER_CONTROL_5              0xC4
#define ILI9488_VCOM_CONTROL                 0xC5

// CABC control blocks
#define ILI9488_CABC_CONTROL_1               0xC6
#define ILI9488_CABC_CONTROL_2               0xC8
#define ILI9488_CABC_CONTROL_3               0xC9
#define ILI9488_CABC_CONTROL_4               0xCA
#define ILI9488_CABC_CONTROL_5               0xCB
#define ILI9488_CABC_CONTROL_6               0xCC
#define ILI9488_CABC_CONTROL_7               0xCD
#define ILI9488_CABC_CONTROL_8               0xCE
#define ILI9488_CABC_CONTROL_9               0xCF

// NV Memory & ID read
#define ILI9488_NV_MEMORY_WRITE              0xD0
#define ILI9488_NV_MEMORY_KEY                0xD1
#define ILI9488_NV_MEMORY_STATUS_READ        0xD2
#define ILI9488_READ_ID4                     0xD3

// Adjustment controls
#define ILI9488_ADJUST_CONTROL_1             0xD7
#define ILI9488_READ_ID_VERSION              0xD8

// Gamma controls
#define ILI9488_POSITIVE_GAMMA_CONTROL       0xE0
#define ILI9488_NEGATIVE_GAMMA_CONTROL       0xE1
#define ILI9488_DIGITAL_GAMMA_CONTROL_1      0xE2
#define ILI9488_DIGITAL_GAMMA_CONTROL_2      0xE3

#define ILI9488_SET_IMAGE_FUNCTION           0xE9

// Additional manufacturer commands (seen in datasheet)
#define ILI9488_ADJUST_CONTROL_2             0xF2
#define ILI9488_ADJUST_CONTROL_3             0xF7
#define ILI9488_ADJUST_CONTROL_4             0xF8
#define ILI9488_ADJUST_CONTROL_5             0xF9

// Aliases (common names)
#define ILI9488_RAMWR                        ILI9488_MEMORY_WRITE
#define ILI9488_RAMRD                        ILI9488_MEMORY_READ
#define ILI9488_RAMWR_CONTINUE               ILI9488_MEMORY_WRITE_CONTINUE
#define ILI9488_RAMRD_CONTINUE               ILI9488_MEMORY_READ_CONTINUE
