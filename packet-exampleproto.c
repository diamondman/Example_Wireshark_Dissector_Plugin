#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include <wireshark/config.h>
#endif

#include <epan/packet.h>

#define EXAMPLEPROTO_PORT 33333

static int proto_example = -1;

static int
dissect_example(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_)
{
    col_set_str(pinfo->cinfo, COL_PROTOCOL, "EXAMPLE");
    /* Clear out stuff in the info column */
    col_clear(pinfo->cinfo,COL_INFO);

    return tvb_captured_length(tvb);
}

void
proto_register_example(void)
{
    proto_example = proto_register_protocol (
        "Example Wireshark Protocol", /* name */
        "Example Proto",              /* short name */
        "example"                     /* abbrev     */
    );
}

void
proto_reg_handoff_example(void)
{
  static dissector_handle_t example_handle;

  example_handle = create_dissector_handle(dissect_example, proto_example);
  dissector_add_uint("udp.port", EXAMPLEPROTO_PORT, example_handle);
}
