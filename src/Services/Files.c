/* Files.c generated by valac 0.20.1, the Vala compiler
 * generated from Files.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <clutter/clutter.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <float.h>
#include <math.h>


#define TYPE_SERVICE (service_get_type ())
#define SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SERVICE, Service))
#define SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SERVICE, ServiceClass))
#define IS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SERVICE))
#define IS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SERVICE))
#define SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SERVICE, ServiceClass))

typedef struct _Service Service;
typedef struct _ServiceClass ServiceClass;
typedef struct _ServicePrivate ServicePrivate;

#define TYPE_FILES (files_get_type ())
#define FILES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FILES, Files))
#define FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FILES, FilesClass))
#define IS_FILES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FILES))
#define IS_FILES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FILES))
#define FILES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FILES, FilesClass))

typedef struct _Files Files;
typedef struct _FilesClass FilesClass;
typedef struct _FilesPrivate FilesPrivate;

#define TYPE_SHADOWED_LABEL (shadowed_label_get_type ())
#define SHADOWED_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SHADOWED_LABEL, ShadowedLabel))
#define SHADOWED_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SHADOWED_LABEL, ShadowedLabelClass))
#define IS_SHADOWED_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SHADOWED_LABEL))
#define IS_SHADOWED_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SHADOWED_LABEL))
#define SHADOWED_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SHADOWED_LABEL, ShadowedLabelClass))

typedef struct _ShadowedLabel ShadowedLabel;
typedef struct _ShadowedLabelClass ShadowedLabelClass;
#define __g_list_free__gtk_recent_info_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__gtk_recent_info_unref0_ (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _gtk_recent_info_unref0(var) ((var == NULL) ? NULL : (var = (gtk_recent_info_unref (var), NULL)))

struct _Service {
	ClutterActor parent_instance;
	ServicePrivate * priv;
};

struct _ServiceClass {
	ClutterActorClass parent_class;
	void (*create) (Service* self);
	gboolean (*update) (Service* self);
};

struct _Files {
	Service parent_instance;
	FilesPrivate * priv;
};

struct _FilesClass {
	ServiceClass parent_class;
};

struct _FilesPrivate {
	GList* last_files;
	ShadowedLabel* files_list;
	GSettings* settings;
};


static gpointer files_parent_class = NULL;

GType service_get_type (void) G_GNUC_CONST;
GType files_get_type (void) G_GNUC_CONST;
GType shadowed_label_get_type (void) G_GNUC_CONST;
#define FILES_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_FILES, FilesPrivate))
enum  {
	FILES_DUMMY_PROPERTY
};
static void _gtk_recent_info_unref0_ (gpointer var);
static void _g_list_free__gtk_recent_info_unref0_ (GList* self);
Files* files_new (void);
Files* files_construct (GType object_type);
Service* service_construct (GType object_type, const gchar* _id);
gboolean service_load (Service* self);
static void files_real_create (Service* base);
#define textcolor "black"
ShadowedLabel* shadowed_label_new (const gchar* _label);
ShadowedLabel* shadowed_label_construct (GType object_type, const gchar* _label);
static gboolean __lambda11_ (Files* self, ClutterButtonEvent* e);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
static gboolean ___lambda11__clutter_actor_button_release_event (ClutterActor* _sender, ClutterButtonEvent* event, gpointer self);
gboolean service_update (Service* self);
static gboolean _service_update_gsource_func (gpointer self);
static gboolean files_real_update (Service* base);
gchar* service_ellipsize (const gchar* s, gint max_length);
void shadowed_label_set_label (ShadowedLabel* self, const gchar* value);
static void files_finalize (GObject* obj);


static void _gtk_recent_info_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (gtk_recent_info_unref (var), NULL));
}


static void _g_list_free__gtk_recent_info_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _gtk_recent_info_unref0_, NULL);
	g_list_free (self);
}


Files* files_construct (GType object_type) {
	Files * self = NULL;
	GtkRecentManager* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	GSettings* _tmp2_;
	self = (Files*) service_construct (object_type, "files");
	_tmp0_ = gtk_recent_manager_get_default ();
	_tmp1_ = gtk_recent_manager_get_items (_tmp0_);
	__g_list_free__gtk_recent_info_unref0_0 (self->priv->last_files);
	self->priv->last_files = _tmp1_;
	_tmp2_ = g_settings_new ("org.pantheon.gazette.files");
	_g_object_unref0 (self->priv->settings);
	self->priv->settings = _tmp2_;
	service_load ((Service*) self);
	return self;
}


Files* files_new (void) {
	return files_construct (TYPE_FILES);
}


static gpointer _gtk_recent_info_ref0 (gpointer self) {
	return self ? gtk_recent_info_ref (self) : NULL;
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static gboolean __lambda11_ (Files* self, ClutterButtonEvent* e) {
	gboolean result = FALSE;
	gfloat root_x = 0.0F;
	gfloat root_y = 0.0F;
	ShadowedLabel* _tmp0_;
	gfloat _tmp1_ = 0.0F;
	gfloat _tmp2_ = 0.0F;
	GList* _tmp3_;
	ClutterButtonEvent _tmp4_;
	gfloat _tmp5_;
	ShadowedLabel* _tmp6_;
	gfloat _tmp7_;
	gfloat _tmp8_;
	gint _tmp9_ = 0;
	gconstpointer _tmp10_ = NULL;
	GtkRecentInfo* _tmp11_;
	GtkRecentInfo* item;
	GList* files;
	const gchar* _tmp12_ = NULL;
	GFile* _tmp13_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (e != NULL, FALSE);
	_tmp0_ = self->priv->files_list;
	clutter_actor_get_transformed_position ((ClutterActor*) _tmp0_, &_tmp1_, &_tmp2_);
	root_x = _tmp1_;
	root_y = _tmp2_;
	_tmp3_ = self->priv->last_files;
	_tmp4_ = *e;
	_tmp5_ = _tmp4_.y;
	_tmp6_ = self->priv->files_list;
	_tmp7_ = clutter_actor_get_height ((ClutterActor*) _tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = MIN ((gint) ((_tmp5_ - root_y) / ((_tmp8_ - 20) / 10.0f)), 9);
	_tmp10_ = g_list_nth_data (_tmp3_, (guint) _tmp9_);
	_tmp11_ = _gtk_recent_info_ref0 ((GtkRecentInfo*) _tmp10_);
	item = _tmp11_;
	files = NULL;
	_tmp12_ = gtk_recent_info_get_uri (item);
	_tmp13_ = g_file_new_for_uri (_tmp12_);
	files = g_list_append (files, _tmp13_);
	{
		const gchar* _tmp14_ = NULL;
		GAppInfo* _tmp15_ = NULL;
		GAppInfo* _tmp16_;
		_tmp14_ = gtk_recent_info_get_mime_type (item);
		_tmp15_ = g_app_info_get_default_for_type (_tmp14_, FALSE);
		_tmp16_ = _tmp15_;
		g_app_info_launch (_tmp16_, files, NULL, &_inner_error_);
		_g_object_unref0 (_tmp16_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp17_;
		const gchar* _tmp18_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp17_ = e;
		_tmp18_ = _tmp17_->message;
		g_warning ("Files.vala:36: %s", _tmp18_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		__g_list_free__g_object_unref0_0 (files);
		_gtk_recent_info_unref0 (item);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	result = TRUE;
	__g_list_free__g_object_unref0_0 (files);
	_gtk_recent_info_unref0 (item);
	return result;
}


static gboolean ___lambda11__clutter_actor_button_release_event (ClutterActor* _sender, ClutterButtonEvent* event, gpointer self) {
	gboolean result;
	result = __lambda11_ (self, event);
	return result;
}


static gboolean _service_update_gsource_func (gpointer self) {
	gboolean result;
	result = service_update (self);
	return result;
}


static void files_real_create (Service* base) {
	Files * self;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	ShadowedLabel* _tmp5_;
	ShadowedLabel* _tmp6_;
	ShadowedLabel* files_label;
	ShadowedLabel* _tmp7_;
	ShadowedLabel* _tmp8_;
	gfloat _tmp9_;
	gfloat _tmp10_;
	ShadowedLabel* _tmp11_;
	ShadowedLabel* _tmp12_;
	ShadowedLabel* _tmp13_;
	GSettings* _tmp14_;
	gint _tmp15_ = 0;
	self = (Files*) base;
	_tmp0_ = _ ("Files");
	_tmp1_ = g_strdup_printf ("' font='20' face='Raleway'>%s</span>", _tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_strconcat ("<span color='" textcolor, _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = shadowed_label_new (_tmp4_);
	g_object_ref_sink (_tmp5_);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp4_);
	_g_free0 (_tmp2_);
	files_label = _tmp6_;
	_tmp7_ = shadowed_label_new ("");
	g_object_ref_sink (_tmp7_);
	_g_object_unref0 (self->priv->files_list);
	self->priv->files_list = _tmp7_;
	_tmp8_ = self->priv->files_list;
	_tmp9_ = clutter_actor_get_height ((ClutterActor*) files_label);
	_tmp10_ = _tmp9_;
	clutter_actor_set_y ((ClutterActor*) _tmp8_, _tmp10_ + 12);
	_tmp11_ = self->priv->files_list;
	clutter_actor_set_x ((ClutterActor*) _tmp11_, (gfloat) 12);
	clutter_actor_add_child ((ClutterActor*) self, (ClutterActor*) files_label);
	_tmp12_ = self->priv->files_list;
	clutter_actor_add_child ((ClutterActor*) self, (ClutterActor*) _tmp12_);
	_tmp13_ = self->priv->files_list;
	g_signal_connect_object ((ClutterActor*) _tmp13_, "button-release-event", (GCallback) ___lambda11__clutter_actor_button_release_event, self, 0);
	_tmp14_ = self->priv->settings;
	_tmp15_ = g_settings_get_int (_tmp14_, "update-interval");
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) _tmp15_, _service_update_gsource_func, g_object_ref ((Service*) self), g_object_unref);
	_g_object_unref0 (files_label);
}


static gboolean files_real_update (Service* base) {
	Files * self;
	gboolean result = FALSE;
	ShadowedLabel* _tmp0_;
	gchar* _tmp1_;
	gchar* res;
	ShadowedLabel* _tmp21_;
	const gchar* _tmp22_;
	gchar* _tmp23_;
	gchar* _tmp24_;
	ShadowedLabel* _tmp25_;
	self = (Files*) base;
	g_debug ("Files.vala:43: Updating Recent Files");
	_tmp0_ = self->priv->files_list;
	clutter_actor_set_reactive ((ClutterActor*) _tmp0_, FALSE);
	_tmp1_ = g_strdup ("<span color='" textcolor "' font='12' face='Open Sans'>");
	res = _tmp1_;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp2_;
			_tmp2_ = TRUE;
			while (TRUE) {
				gboolean _tmp3_;
				gboolean _tmp5_ = FALSE;
				gint _tmp6_;
				gboolean _tmp10_;
				const gchar* _tmp11_;
				GList* _tmp12_;
				gint _tmp13_;
				gconstpointer _tmp14_ = NULL;
				const gchar* _tmp15_ = NULL;
				gchar* _tmp16_ = NULL;
				gchar* _tmp17_;
				gchar* _tmp18_;
				gchar* _tmp19_;
				gchar* _tmp20_;
				_tmp3_ = _tmp2_;
				if (!_tmp3_) {
					gint _tmp4_;
					_tmp4_ = i;
					i = _tmp4_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp6_ = i;
				if (_tmp6_ < 10) {
					gint _tmp7_;
					GList* _tmp8_;
					guint _tmp9_ = 0U;
					_tmp7_ = i;
					_tmp8_ = self->priv->last_files;
					_tmp9_ = g_list_length (_tmp8_);
					_tmp5_ = ((guint) _tmp7_) < _tmp9_;
				} else {
					_tmp5_ = FALSE;
				}
				_tmp10_ = _tmp5_;
				if (!_tmp10_) {
					break;
				}
				_tmp11_ = res;
				_tmp12_ = self->priv->last_files;
				_tmp13_ = i;
				_tmp14_ = g_list_nth_data (_tmp12_, (guint) _tmp13_);
				_tmp15_ = gtk_recent_info_get_display_name ((GtkRecentInfo*) _tmp14_);
				_tmp16_ = service_ellipsize (_tmp15_, 40);
				_tmp17_ = _tmp16_;
				_tmp18_ = g_strconcat (_tmp17_, "\n", NULL);
				_tmp19_ = _tmp18_;
				_tmp20_ = g_strconcat (_tmp11_, _tmp19_, NULL);
				_g_free0 (res);
				res = _tmp20_;
				_g_free0 (_tmp19_);
				_g_free0 (_tmp17_);
			}
		}
	}
	_tmp21_ = self->priv->files_list;
	_tmp22_ = res;
	_tmp23_ = g_strconcat (_tmp22_, "</span>", NULL);
	_tmp24_ = _tmp23_;
	shadowed_label_set_label (_tmp21_, _tmp24_);
	_g_free0 (_tmp24_);
	_tmp25_ = self->priv->files_list;
	clutter_actor_set_reactive ((ClutterActor*) _tmp25_, TRUE);
	result = TRUE;
	_g_free0 (res);
	return result;
}


static void files_class_init (FilesClass * klass) {
	files_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FilesPrivate));
	SERVICE_CLASS (klass)->create = files_real_create;
	SERVICE_CLASS (klass)->update = files_real_update;
	G_OBJECT_CLASS (klass)->finalize = files_finalize;
}


static void files_instance_init (Files * self) {
	self->priv = FILES_GET_PRIVATE (self);
}


static void files_finalize (GObject* obj) {
	Files * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_FILES, Files);
	__g_list_free__gtk_recent_info_unref0_0 (self->priv->last_files);
	_g_object_unref0 (self->priv->files_list);
	_g_object_unref0 (self->priv->settings);
	G_OBJECT_CLASS (files_parent_class)->finalize (obj);
}


GType files_get_type (void) {
	static volatile gsize files_type_id__volatile = 0;
	if (g_once_init_enter (&files_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FilesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) files_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Files), 0, (GInstanceInitFunc) files_instance_init, NULL };
		GType files_type_id;
		files_type_id = g_type_register_static (TYPE_SERVICE, "Files", &g_define_type_info, 0);
		g_once_init_leave (&files_type_id__volatile, files_type_id);
	}
	return files_type_id__volatile;
}



