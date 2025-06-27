/*
 * Nuklear - v1.40.8 - public domain
 * no warrenty implied; use at your own risk.
 * authored from 2015-2017 by Micha Mettke
 */
/*
 * ==============================================================
 *
 *                              API
 *
 * ===============================================================
 */
#ifndef NK_NCURSES_H_
#define NK_NCURSES_H_

#include <ncurses.h>


NK_INTERN unsigned long
nk_color_from_byte(const nk_byte *c)

{
    unsigned long res = 0;
    res |= (unsigned long)c[0] << 16;
    res |= (unsigned long)c[1] << 8;
    res |= (unsigned long)c[2] << 0;
    return (res);
}

NK_INTERN double
nk_get_time(void)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) < 0) return 0;
    return ((double)tv.tv_sec + (double)tv.tv_usec/1000000);
}

NK_API void nk_ncurses_render(struct nk_context *ctx)
{
    const struct nk_command *cmd;
    static double prev_frame = 0;
    static double now = 0;
    now = nk_get_time();
    ctx->delta_time_seconds = now - prev_frame;
    prev_frame = now;

    nk_foreach(cmd, ctx)
    {
        switch (cmd->type) 
        {
            case NK_COMMAND_NOP: break;
            case NK_COMMAND_SCISSOR: 
                                    {
                                    const struct nk_command_scissor *s =(const struct nk_command_scissor*)cmd;
                                    printw("scissor");
                                    }
                                 break;
            case NK_COMMAND_LINE: 
                                    const struct nk_command_line *l = (const struct nk_command_line *)cmd;
                                    if( l->begin.x == l->end.x ) /* vertical */
                                        mvvline(l->begin.y, l->begin.x, 0, l->end.y);
                                    else if( l->begin.y == l->end.y ) /* horizontal */
                                        mvhline(l->begin.y, l->begin.x, 0, l->end.x);
                                    else
                                    printw("line");
                                 break;
            case NK_COMMAND_RECT: 
                                 {
                                     const struct nk_command_rect_filled *r = (const struct nk_command_rect_filled *)cmd;
                                     int i, j;
                                     int x, y, w, h;

                                     x = r->x;
                                     y = r->y;
                                     w = r->w;
                                     h = r->h;

                                     mvaddch(y     , x     , '+');
                                     mvaddch(y     , x + w , '+');
                                     mvaddch(y + h , x     , '+');
                                     mvaddch(y + h , x + w , '+');
                                     mvhline(y     , x + 1 , 0   , w - 1);
                                     mvhline(y + h , x + 1 , 0   , w - 1);
                                     mvvline(y + 1 , x     , 0   , h - 1);
                                     mvvline(y + 1 , x + w , 0   , h - 1);

                                 }
                                 break;
            case NK_COMMAND_RECT_FILLED: 
                                 {
                                     const struct nk_command_rect_filled *r = (const struct nk_command_rect_filled *)cmd;
                                     int i, j;
                                     int x, y, w, h;

                                     x = r->x;
                                     y = r->y;
                                     w = r->w;
                                     h = r->h;

                                     mvaddch(y     , x     , '+');
                                     mvaddch(y     , x + w , '+');
                                     mvaddch(y + h , x     , '+');
                                     mvaddch(y + h , x + w , '+');
                                     mvhline(y     , x + 1 , 0   , w - 1);
                                     mvhline(y + h , x + 1 , 0   , w - 1);
                                     mvvline(y + 1 , x     , 0   , h - 1);
                                     mvvline(y + 1 , x + w , 0   , h - 1);

                                 }
                                 break;
            case NK_COMMAND_CIRCLE: 
                                 /*
                                    {
                                    const struct nk_command_circle *c = (const struct nk_command_circle *)cmd;
                                    nk_xsurf_stroke_circle(surf, c->x, c->y, c->w, c->h, c->line_thickness, c->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_CIRCLE_FILLED: 
                                 /*
                                    {
                                    const struct nk_command_circle_filled *c = (const struct nk_command_circle_filled *)cmd;
                                    nk_xsurf_fill_circle(surf, c->x, c->y, c->w, c->h, c->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_ARC: 
                                 /*
                                    {
                                    const struct nk_command_arc *a = (const struct nk_command_arc *)cmd;
                                    nk_xsurf_stroke_arc(surf, a->cx, a->cy, a->r, a->a[0], a->a[1], a->line_thickness, a->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_ARC_FILLED: 
                                 /*
                                    {
                                    const struct nk_command_arc_filled *a = (const struct nk_command_arc_filled *)cmd;
                                    nk_xsurf_fill_arc(surf, a->cx, a->cy, a->r, a->a[0], a->a[1], a->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_TRIANGLE: 
                                 /*
                                    {
                                    const struct nk_command_triangle*t = (const struct nk_command_triangle*)cmd;
                                    nk_xsurf_stroke_triangle(surf, t->a.x, t->a.y, t->b.x, t->b.y,
                                    t->c.x, t->c.y, t->line_thickness, t->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_TRIANGLE_FILLED: 
                                 /*
                                    {
                                    const struct nk_command_triangle_filled *t = (const struct nk_command_triangle_filled *)cmd;
                                    nk_xsurf_fill_triangle(surf, t->a.x, t->a.y, t->b.x, t->b.y,
                                    t->c.x, t->c.y, t->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_POLYGON: 
                                 /*
                                    {
                                    const struct nk_command_polygon *p =(const struct nk_command_polygon*)cmd;
                                    nk_xsurf_stroke_polygon(surf, p->points, p->point_count, p->line_thickness,p->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_POLYGON_FILLED: 
                                 /*
                                    {
                                    const struct nk_command_polygon_filled *p = (const struct nk_command_polygon_filled *)cmd;
                                    nk_xsurf_fill_polygon(surf, p->points, p->point_count, p->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_POLYLINE: 
                                 /*
                                    {
                                    const struct nk_command_polyline *p = (const struct nk_command_polyline *)cmd;
                                    nk_xsurf_stroke_polyline(surf, p->points, p->point_count, p->line_thickness, p->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_TEXT: 
                                 {
                                     const struct nk_command_text *t = (const struct nk_command_text*)cmd;
                                     printw("%s", (const char*)t->string);
                                     /*mvprintw(t->y, t->x, "%s", (const char*)t->string);*/
                                 }
                                 break;
            case NK_COMMAND_CURVE: 
                                 /*
                                    {
                                    const struct nk_command_curve *q = (const struct nk_command_curve *)cmd;
                                    nk_xsurf_stroke_curve(surf, q->begin, q->ctrl[0], q->ctrl[1],
                                    q->end, 22, q->line_thickness, q->color);
                                    }
                                    */
                                 break;
            case NK_COMMAND_IMAGE: 
                                 /*
                                    {
                                    const struct nk_command_image *i = (const struct nk_command_image *)cmd;
                                    nk_xsurf_draw_image(surf, i->x, i->y, i->w, i->h, i->img, i->col);
                                    }
                                    */
                                 break;
            case NK_COMMAND_RECT_MULTI_COLOR:
                                 /*
                                 */
            case NK_COMMAND_CUSTOM:
                                 /*
                                 */
                                    printw("custom");
            default: break;
        }
    }
    nk_clear(ctx);
    refresh();
}
#endif
