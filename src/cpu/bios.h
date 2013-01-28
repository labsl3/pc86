#ifndef __BIOS_H
#define __BIOS_H

#include "cpu.h"

/*! \brief BIOS Data Area (segment 40h) */
struct bda_40h_t
{
     int16_t com[4];                    /*!< RS232 COM ports, 0 if none */
     int16_t lpt[4];                    /*!< Printers ports, 0 if none */

     /* present equipment */

     int16_t equip_floppies      : 2;   /*!< 1 if floppies present */
     int16_t equip_nb_sysram_64k : 2;   /*!< number of 64k sys ram */
     int16_t equip_crt_mode      : 2;   /*!< init crt mode */
     int16_t equip_nb_floppies   : 2;   /*!< number of floppy drives */
     int16_t equip_nb_serials    : 2;   /*!< number of serial ports */
     int16_t equip_toy           : 2;   /*!< 1 if toy port present */
     int16_t equip_lpt           : 2;   /*!< number of parallel LPT ports */

     int8_t  mfg;                       /*!< MFG test flags */
     int16_t mem_size;                  /*!< Memory size (in kilobytes) */
     int8_t  ipl_errors;                /*!< IPL errors <- table/scratchpad */
     int8_t                      : 8;   /*!< unused */

     /* keyboard data area */

     int16_t kb_flags;                  /*!< Shift/Alt/etc. keyboard flags */
     int8_t  kb_alt;                    /*!< ALT-Keypad character goes here */
     int16_t kb_buf_head;               /*!< Keyboard buffer head */
     int16_t kb_buf_tail;               /*!< Keyboard buffer tail */
     int16_t kb_buffer[16];             /*!< Keyboard buffer (scan,value) */

     /* diskette data area */

     int8_t  floppy_calibration;        /*!< Drive calibration bit 0 - 3 */
     int8_t  floppy_motors;             /*!< Drive motor(s) bit 0 - 3, 7 = write */
     int8_t  floppy_ticks;              /*!< Ticks (18/sec) until motor off */
     int8_t  floppy_retcode;            /*!< Floppy return code stat byte
                                         *     1 = bad ic 735 command req
                                         *     2 = address mark not found
                                         *     3 = write to protected disk
                                         *     4 = sector not found
                                         *     8 = data late (DMA overrun)
                                         *     9 = DMA failed 64k page end
                                         *    16 = bad CRC on floppy read
                                         */
     int8_t  floppy_retcode_NEC765[7];  /*!< Status bytes from NEC 765 :
                                         *    32 = bad NEC 765 controller
                                         *    64 = seek operation failed
                                         *   128 = disk drive timed out
                                         */

     /* video display area */

     int8_t  video_crt_mode;            /*!< Current CRT mode (software)
                                         *     0 = 40x25 text (no color)
                                         *     1 = 40x25 text (16 colors)
                                         *     2 = 80x25 text (no color)
                                         *     3 = 80x25 text (16 colors)
                                         *     4 = 320x200 graphics (4 colors)
                                         *     5 = 320x200 graphics (no color)
                                         *     6 = 640x200 graphics (no color)
                                         *     7 = 80x25 text (mono card)
                                         */

     int16_t video_crt_columns;         /*!< Columns on CRT screen */
     int16_t video_regen_bytes;         /*!< Bytes in the regen region */
     int16_t video_regen_offset;        /*!< Byte offset in regen region */
     int16_t video_cursor_pos[8];       /*!< Cursor position for up to 8 pages */
     int16_t video_cursor_mode;         /*!< Current cursor mode setting */
     int8_t  video_current_page;        /*!< Current page on display */
     int16_t video_base_address;        /*!< Base address (A000h or B800h) */
     int8_t  video_ic6845_mode;         /*!< ic 6845 mode reg. (hardware) */
     int8_t  video_cga_palette;         /*!< Current CGA palette */

     /* used to setup ROM */

     int16_t eprom_base_offset;         /*!< EPROM base offset */
     int16_t eprom_base_segment;        /*!< EPROM base segment */
     int8_t  eprom_last_irq;            /*!< Last spurious interrupt IRQ */

     /* timer data area */

     int32_t timer_ticks;               /*!< Ticks since midnite */
     int8_t  timer_newday;              /*!< Non-zero if new day */

     /* system data area */

     int8_t  sys_sign;                  /*!< Sign bit set if break */
     int16_t sys_warm;                  /*!< Warm boot if 1234h value */

     /* hard disk scratchpad */

     int16_t hdd_unused[2];             /*!< ?? */

     /* timeout areas/PRT/LPT */

     int8_t timeout_lpt[4];             /*!< Ticks for LPT 1-4 timeouts */
     int8_t timeout_com[4];             /*!< Ticks for COM 1-4 timeouts */

     /* keyboard buffer start/end */

     int16_t kbbuf_start;               /*!< Contains 1Eh, buffer start */
     int16_t kbbuf_end;                 /*!< Contains 3Eh, buffer end */
} __attribute__((packed));

/*! Descriebe a BIOS structure */
struct bios_t
{
     struct cpu_t *cpu;                 /*!< Associated CPU */

     struct bda_40h_t *bda_40h;         /*!< Pointer to the 40h segment */
};

struct bios_t *bios_start (struct cpu_t *cpu);

#endif /* __BIOS_H */
