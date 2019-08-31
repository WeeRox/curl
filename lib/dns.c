/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2019, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include "curl_setup.h"

#include <curl/curl.h>
#include "urldata.h"

/* The last 3 #include files should be in this order */
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"

static CURLcode dns_setup_connection(struct connectdata *conn);

const struct Curl_handler Curl_handler_dns = {
  "DNS",                                /* scheme */
  dns_setup_connection,                 /* setup_connection */
  ZERO_NULL,                            /* do_it */
  ZERO_NULL,                            /* done */
  ZERO_NULL,                            /* do_more */
  ZERO_NULL,                            /* connect_it */
  ZERO_NULL,                            /* connecting */
  ZERO_NULL,                            /* doing */
  ZERO_NULL,                            /* proto_getsock */
  ZERO_NULL,                            /* doing_getsock */
  ZERO_NULL,                            /* domore_getsock */
  ZERO_NULL,                            /* perform_getsock */
  ZERO_NULL,                            /* disconnect */
  ZERO_NULL,                            /* readwrite */
  ZERO_NULL,                            /* connection_check */
  PORT_DNS,                             /* defport */
  CURLPROTO_DNS,                        /* protocol */
  PROTOPT_NONE                          /* flags */
};

static CURLcode dns_setup_connection(struct connectdata *conn)
{
  CURLcode result = CURLE_OK;
  struct Curl_easy *data = conn->data;

/*
  char *scheme;
  curl_url_get(data->set.uh, CURLUPART_URL, &scheme, 0);
  printf("%s\n", scheme);*/
  printf("test\n");
  printf("scheme: %s\n", data->state.up.scheme);
  printf("path: %s\n", data->state.up.path);
  printf("query: %s\n", data->state.up.query);

  if(data->set.uh)
    printf("true\n");
  else
    printf("false\n");
  /*curl_free(scheme);*/

  return result;
}
