/**
 * SECTION:iface
 * @short_description: interface for gtk-doc unit test
 *
 * This file contains non-sense code for the sole purpose of testing the docs.
 * We can link to the #GtkdocIface:test property and the #GtkdocIface::test
 * signal.
 * An instance can be configured using the gtkdoc_iface_configure() function.
 */

#include <glib.h>
#include <glib-object.h>

#include "giface.h"

/* constructor methods */

/* methods */

/**
 * gtkdoc_iface_configure:
 * @config: settings
 *
 * Configure a new instance
 *
 * Returns: %TRUE for sucess or %FALSE in case of an error
 */
gboolean gtkdoc_iface_configure (gchar *config) {
  return(TRUE);
}

/* class internals */

static void gtkdoc_iface_base_init (gpointer g_class) {
  static gboolean initialized = FALSE;

  if (!initialized) {
    /**
     * GtkdocIface::test:
     * @self: myself
     *
     * The event has been triggered.
     */
    g_signal_new ("itest", G_TYPE_FROM_CLASS (g_class),
                  G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,
                  G_STRUCT_OFFSET (GtkdocIfaceInterface,test),
                  NULL, // accumulator
                  NULL, // acc data
                  g_cclosure_marshal_VOID__OBJECT,
                  G_TYPE_NONE, // return type
                  0); // n_params
  
    g_object_interface_install_property (g_class ,
                                    g_param_spec_string ("itest",
                                       "itest prop",
                                       "dummy property for iface",
                                       "dummy", /* default value */
                                       G_PARAM_READWRITE));
    initialized = TRUE;
  }
}

GType gtkdoc_iface_get_type (void) {
  static GType type = 0;
  if (type == 0) {
    static const GTypeInfo info = {
      (guint16)sizeof(GtkdocIfaceInterface),
      gtkdoc_iface_base_init, // base_init
      NULL, // base_finalize
      NULL, // class_init
      NULL, // class_finalize
      NULL, // class_data
      0,
      0,   // n_preallocs
      NULL, // instance_init
      NULL // value_table
    };
    type = g_type_register_static(G_TYPE_INTERFACE,"GtkdocIface",&info,0);
  }
  return type;
}

