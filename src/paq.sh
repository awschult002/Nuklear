#!/bin/sh
python3 \
build.py \
--macro \
NK \
--intro \
../HEADER.md \
--pub \
nuklear.h \
--priv1 \
nuklear_internal.h,\
nuklear_math.c,\
nuklear_util.c,\
nuklear_color.c,\
nuklear_utf8.c,\
nuklear_buffer.c,\
nuklear_string.c,\
nuklear_draw.c,\
nuklear_vertex.c \
--extern \
stb_rect_pack.h,stb_truetype.h \
--priv2 \
nuklear_font.c,\
nuklear_input.c,\
nuklear_style.c,\
nuklear_context.c,\
nuklear_pool.c,\
nuklear_page_element.c,\
nuklear_table.c,\
nuklear_panel.c,\
nuklear_window.c,\
nuklear_popup.c,\
nuklear_contextual.c,\
nuklear_menu.c,\
nuklear_layout.c,\
nuklear_tree.c,\
nuklear_group.c,\
nuklear_list_view.c,\
nuklear_widget.c,\
nuklear_text.c,\
nuklear_image.c,\
nuklear_9slice.c,\
nuklear_button.c,\
nuklear_toggle.c,\
nuklear_selectable.c,\
nuklear_slider.c,\
nuklear_knob.c,\
nuklear_progress.c,\
nuklear_scrollbar.c,\
nuklear_text_editor.c,\
nuklear_edit.c,\
nuklear_property.c,\
nuklear_chart.c,\
nuklear_color_picker.c,\
nuklear_combo.c,\
nuklear_tooltip.c \
--outro \
../LICENSE,../CHANGELOG.md,../CREDITS.md \
> \
../nuklear.h
