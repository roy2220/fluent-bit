/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2017 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_HS_MAIN_H
#define FLB_HS_MAIN_H

#include <fluent-bit/flb_info.h>
#include <fluent-bit/flb_config.h>
#include <monkey/mk_lib.h>

struct flb_hs {
    mk_ctx_t *ctx;             /* Monkey HTTP Context */
    pthread_t tid;             /* Server Thread */
    struct flb_config *config; /* Fluent Bit context */

    /* end-point: root */
    size_t ep_root_size;
    char *ep_root_buf;
};

struct flb_hs *flb_hs_create(char *tcp_port);
int flb_hs_destroy(struct flb_hs *ctx);

int flb_hs_start(struct flb_hs *hs);

#endif