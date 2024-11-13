#include "nuklear.h"
#include "nuklear_internal.h"

/* ===============================================================
 *
 *                          9-SLICE
 *
 * ===============================================================*/
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] ptr <fill in>
 * \param[in] w <fill in>
 * \param[in] h <fill in>
 * \param[in] rgn <fill in>
 * \param[in] l <fill in>
 *
 * \returns <fill in>
 */
NK_API struct nk_nine_slice
nk_sub9slice_ptr(void *ptr, nk_ushort w, nk_ushort h, struct nk_rect rgn, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b)
{
    struct nk_nine_slice s;
    struct nk_image *i = &s.img;
    nk_zero(&s, sizeof(s));
    i->handle.ptr = ptr;
    i->w = w; i->h = h;
    i->region[0] = (nk_ushort)rgn.x;
    i->region[1] = (nk_ushort)rgn.y;
    i->region[2] = (nk_ushort)rgn.w;
    i->region[3] = (nk_ushort)rgn.h;
    s.l = l; s.t = t; s.r = r; s.b = b;
    return s;
}
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] id <fill in>
 * \param[in] w <fill in>
 * \param[in] h <fill in>
 * \param[in] rgn <fill in>
 * \param[in] l <fill in>
 * \param[in] t <fill in>
 *
 * \returns <fill in>
 */
NK_API struct nk_nine_slice
nk_sub9slice_id(int id, nk_ushort w, nk_ushort h, struct nk_rect rgn, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b)
{
    struct nk_nine_slice s;
    struct nk_image *i = &s.img;
    nk_zero(&s, sizeof(s));
    i->handle.id = id;
    i->w = w; i->h = h;
    i->region[0] = (nk_ushort)rgn.x;
    i->region[1] = (nk_ushort)rgn.y;
    i->region[2] = (nk_ushort)rgn.w;
    i->region[3] = (nk_ushort)rgn.h;
    s.l = l; s.t = t; s.r = r; s.b = b;
    return s;
}
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] handle <fill in>
 * \param[in] w <fill in>
 * \param[in] h <fill in>
 * \param[in] rgn <fill in>
 * \param[in] l <fill in>
 *
 * \returns <fill in>
 */
NK_API struct nk_nine_slice
nk_sub9slice_handle(nk_handle handle, nk_ushort w, nk_ushort h, struct nk_rect rgn, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b)
{
    struct nk_nine_slice s;
    struct nk_image *i = &s.img;
    nk_zero(&s, sizeof(s));
    i->handle = handle;
    i->w = w; i->h = h;
    i->region[0] = (nk_ushort)rgn.x;
    i->region[1] = (nk_ushort)rgn.y;
    i->region[2] = (nk_ushort)rgn.w;
    i->region[3] = (nk_ushort)rgn.h;
    s.l = l; s.t = t; s.r = r; s.b = b;
    return s;
}
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] handle <fill in>
 * \param[in] l <fill in>
 * \param[in] t <fill in>
 * \param[in] r <fill in>
 * \param[in] b <fill in>
 *
 * \returns <fill in>
 */
NK_API struct nk_nine_slice
nk_nine_slice_handle(nk_handle handle, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b)
{
    struct nk_nine_slice s;
    struct nk_image *i = &s.img;
    nk_zero(&s, sizeof(s));
    i->handle = handle;
    i->w = 0; i->h = 0;
    i->region[0] = 0;
    i->region[1] = 0;
    i->region[2] = 0;
    i->region[3] = 0;
    s.l = l; s.t = t; s.r = r; s.b = b;
    return s;
}
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] ptr <fill in>
 * \param[in] l <fill in>
 * \param[in] t <fill in>
 * \param[in] r <fill in>
 * \param[in] b <fill in>
 *
 * \returns <fill in>
 */
NK_API struct nk_nine_slice
nk_nine_slice_ptr(void *ptr, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b)
{
    struct nk_nine_slice s;
    struct nk_image *i = &s.img;
    nk_zero(&s, sizeof(s));
    NK_ASSERT(ptr);
    i->handle.ptr = ptr;
    i->w = 0; i->h = 0;
    i->region[0] = 0;
    i->region[1] = 0;
    i->region[2] = 0;
    i->region[3] = 0;
    s.l = l; s.t = t; s.r = r; s.b = b;
    return s;
}
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] id <fill in>
 * \param[in] l <fill in>
 * \param[in] t <fill in>
 * \param[in] r <fill in>
 * \param[in] b <fill in>
 *
 * \returns <fill in>
 */
NK_API struct nk_nine_slice
nk_nine_slice_id(int id, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b)
{
    struct nk_nine_slice s;
    struct nk_image *i = &s.img;
    nk_zero(&s, sizeof(s));
    i->handle.id = id;
    i->w = 0; i->h = 0;
    i->region[0] = 0;
    i->region[1] = 0;
    i->region[2] = 0;
    i->region[3] = 0;
    s.l = l; s.t = t; s.r = r; s.b = b;
    return s;
}
/**
 * \brief <fill in>
 *
 * \details
 * <fill in>
 *
 * \param[in] slice <fill in>
 *
 * \returns <fill in>
 */
NK_API int
nk_nine_slice_is_sub9slice(const struct nk_nine_slice* slice)
{
    NK_ASSERT(slice);
    return !(slice->img.w == 0 && slice->img.h == 0);
}

