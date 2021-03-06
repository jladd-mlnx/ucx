/**
 * Copyright (C) Mellanox Technologies Ltd. 2001-2015.  ALL RIGHTS RESERVED.
 *
 * See file LICENSE for terms.
 */

#ifndef UCP_TAG_RNDV_H_
#define UCP_TAG_RNDV_H_

#include "match.h"

#include <ucp/api/ucp.h>
#include <ucp/core/ucp_request.h>
#include <ucp/proto/proto.h>

/*
 * Rendezvous RTS
 */
typedef struct {
    ucp_tag_hdr_t             super;
    ucp_request_hdr_t         req;      /* request on the rndv initiator side */
    uint64_t                  address;  /* holds the address of the data on the sender's side */
    size_t                    size;     /* size of the data for sending */
    /* packed rkey follows */
} UCS_S_PACKED ucp_rndv_rts_hdr_t;

ucs_status_t ucp_tag_send_start_rndv(ucp_request_t *req);

void ucp_rndv_matched(ucp_worker_h worker, ucp_request_t *req,
                      ucp_rndv_rts_hdr_t *rndv_rts_hdr);

ucs_status_t ucp_proto_progress_rndv_get(uct_pending_req_t *self);

static inline size_t ucp_rndv_total_len(ucp_rndv_rts_hdr_t *hdr)
{
    return hdr->size;
}

#endif
