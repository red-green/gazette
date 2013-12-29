/* News.c generated by valac 0.20.1, the Vala compiler
 * generated from News.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <clutter/clutter.h>
#include <gio/gio.h>
#include <libsoup/soup.h>
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

#define TYPE_NEWS (news_get_type ())
#define NEWS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_NEWS, News))
#define NEWS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_NEWS, NewsClass))
#define IS_NEWS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_NEWS))
#define IS_NEWS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_NEWS))
#define NEWS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_NEWS, NewsClass))

typedef struct _News News;
typedef struct _NewsClass NewsClass;
typedef struct _NewsPrivate NewsPrivate;

#define TYPE_SHADOWED_LABEL (shadowed_label_get_type ())
#define SHADOWED_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SHADOWED_LABEL, ShadowedLabel))
#define SHADOWED_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SHADOWED_LABEL, ShadowedLabelClass))
#define IS_SHADOWED_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SHADOWED_LABEL))
#define IS_SHADOWED_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SHADOWED_LABEL))
#define SHADOWED_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SHADOWED_LABEL, ShadowedLabelClass))

typedef struct _ShadowedLabel ShadowedLabel;
typedef struct _ShadowedLabelClass ShadowedLabelClass;

#define NEWS_TYPE_NEWS (news_news_get_type ())
typedef struct _NewsNews NewsNews;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define __g_list_free__g_free0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_free0_ (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _Service {
	ClutterActor parent_instance;
	ServicePrivate * priv;
};

struct _ServiceClass {
	ClutterActorClass parent_class;
	void (*create) (Service* self);
	gboolean (*update) (Service* self);
};

struct _News {
	Service parent_instance;
	NewsPrivate * priv;
};

struct _NewsClass {
	ServiceClass parent_class;
};

struct _NewsNews {
	gchar* title;
	gchar* url;
};

struct _NewsPrivate {
	GSettings* settings;
	SoupSession* session;
	SoupMessage* message;
	ShadowedLabel* label_list;
	ShadowedLabel* reload;
	NewsNews* news;
	gint news_length1;
	gint _news_size_;
};


static gpointer news_parent_class = NULL;

GType service_get_type (void) G_GNUC_CONST;
GType news_get_type (void) G_GNUC_CONST;
GType shadowed_label_get_type (void) G_GNUC_CONST;
static GType news_news_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
static NewsNews* news_news_dup (const NewsNews* self);
static void news_news_free (NewsNews* self);
static void news_news_copy (const NewsNews* self, NewsNews* dest);
static void news_news_destroy (NewsNews* self);
#define NEWS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_NEWS, NewsPrivate))
enum  {
	NEWS_DUMMY_PROPERTY
};
static void _vala_NewsNews_array_free (NewsNews* array, gint array_length);
News* news_new (void);
News* news_construct (GType object_type);
Service* service_construct (GType object_type, const gchar* _id);
ShadowedLabel* service_get_reload_label (Service* self, const gchar* service_name);
ShadowedLabel* shadowed_label_new (const gchar* _label);
ShadowedLabel* shadowed_label_construct (GType object_type, const gchar* _label);
static gboolean __lambda14_ (News* self, ClutterButtonEvent* e);
static void _g_free0_ (gpointer var);
static void _g_list_free__g_free0_ (GList* self);
static gboolean ___lambda14__clutter_actor_button_release_event (ClutterActor* _sender, ClutterButtonEvent* event, gpointer self);
static void __lambda15_ (News* self, const gchar* key);
gboolean service_update (Service* self);
static void ___lambda15__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
gboolean service_load (Service* self);
static gboolean _service_update_gsource_func (gpointer self);
#define textcolor "black"
static void news_real_create (Service* base);
static gboolean news_real_update (Service* base);
void shadowed_label_set_label (ShadowedLabel* self, const gchar* value);
static void __lambda16_ (News* self, SoupSession* session, SoupMessage* m);
gchar* service_ellipsize (const gchar* s, gint max_length);
static void ___lambda16__soup_session_callback (SoupSession* session, SoupMessage* msg, gpointer self);
static void news_finalize (GObject* obj);


static void _vala_NewsNews_array_free (NewsNews* array, gint array_length) {
	if (array != NULL) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			news_news_destroy (&array[i]);
		}
	}
	g_free (array);
}


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_list_free__g_free0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_free0_, NULL);
	g_list_free (self);
}


static gboolean __lambda14_ (News* self, ClutterButtonEvent* e) {
	gboolean result = FALSE;
	gfloat root_x = 0.0F;
	gfloat root_y = 0.0F;
	ShadowedLabel* _tmp0_;
	gfloat _tmp1_ = 0.0F;
	gfloat _tmp2_ = 0.0F;
	NewsNews* _tmp3_;
	gint _tmp3__length1;
	ClutterButtonEvent _tmp4_;
	gfloat _tmp5_;
	ShadowedLabel* _tmp6_;
	gfloat _tmp7_;
	gfloat _tmp8_;
	gint _tmp9_ = 0;
	NewsNews _tmp10_;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* url;
	GList* uris;
	gchar* _tmp13_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (e != NULL, FALSE);
	_tmp0_ = self->priv->label_list;
	clutter_actor_get_transformed_position ((ClutterActor*) _tmp0_, &_tmp1_, &_tmp2_);
	root_x = _tmp1_;
	root_y = _tmp2_;
	_tmp3_ = self->priv->news;
	_tmp3__length1 = self->priv->news_length1;
	_tmp4_ = *e;
	_tmp5_ = _tmp4_.y;
	_tmp6_ = self->priv->label_list;
	_tmp7_ = clutter_actor_get_height ((ClutterActor*) _tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = MIN ((gint) ((_tmp5_ - root_y) / ((_tmp8_ - 20) / 10.0f)), 9);
	_tmp10_ = _tmp3_[_tmp9_];
	_tmp11_ = _tmp10_.url;
	_tmp12_ = g_strdup (_tmp11_);
	url = _tmp12_;
	uris = NULL;
	_tmp13_ = g_strdup (url);
	uris = g_list_append (uris, _tmp13_);
	{
		GAppInfo* _tmp14_ = NULL;
		GAppInfo* _tmp15_;
		_tmp14_ = g_app_info_get_default_for_uri_scheme ("http");
		_tmp15_ = _tmp14_;
		g_app_info_launch_uris (_tmp15_, uris, NULL, &_inner_error_);
		_g_object_unref0 (_tmp15_);
		if (_inner_error_ != NULL) {
			goto __catch2_g_error;
		}
	}
	goto __finally2;
	__catch2_g_error:
	{
		GError* e = NULL;
		GError* _tmp16_;
		const gchar* _tmp17_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp16_ = e;
		_tmp17_ = _tmp16_->message;
		g_warning ("News.vala:32: %s", _tmp17_);
		_g_error_free0 (e);
	}
	__finally2:
	if (_inner_error_ != NULL) {
		__g_list_free__g_free0_0 (uris);
		_g_free0 (url);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	result = TRUE;
	__g_list_free__g_free0_0 (uris);
	_g_free0 (url);
	return result;
}


static gboolean ___lambda14__clutter_actor_button_release_event (ClutterActor* _sender, ClutterButtonEvent* event, gpointer self) {
	gboolean result;
	result = __lambda14_ (self, event);
	return result;
}


static void __lambda15_ (News* self, const gchar* key) {
	const gchar* _tmp0_;
	g_return_if_fail (key != NULL);
	_tmp0_ = key;
	if (g_strcmp0 (_tmp0_, "update-interval") != 0) {
		service_update ((Service*) self);
	}
}


static void ___lambda15__g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	__lambda15_ (self, key);
}


static gboolean _service_update_gsource_func (gpointer self) {
	gboolean result;
	result = service_update (self);
	return result;
}


News* news_construct (GType object_type) {
	News * self = NULL;
	const gchar* _tmp0_ = NULL;
	ShadowedLabel* _tmp1_ = NULL;
	ShadowedLabel* _tmp2_;
	ShadowedLabel* _tmp3_;
	ShadowedLabel* _tmp4_;
	ShadowedLabel* _tmp5_;
	ShadowedLabel* _tmp6_;
	GSettings* _tmp7_;
	GSettings* _tmp8_;
	SoupSessionAsync* _tmp9_;
	GSettings* _tmp10_;
	gint _tmp11_ = 0;
	const gchar* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
	ShadowedLabel* _tmp17_;
	ShadowedLabel* _tmp18_;
	ShadowedLabel* label;
	ShadowedLabel* _tmp19_;
	gfloat _tmp20_;
	gfloat _tmp21_;
	ShadowedLabel* _tmp22_;
	ShadowedLabel* _tmp23_;
	ShadowedLabel* _tmp24_;
	gfloat _tmp25_;
	gfloat _tmp26_;
	ShadowedLabel* _tmp27_;
	ShadowedLabel* _tmp28_;
	gfloat _tmp29_;
	gfloat _tmp30_;
	ShadowedLabel* _tmp31_;
	ShadowedLabel* _tmp32_;
	self = (News*) service_construct (object_type, "news");
	_tmp0_ = _ ("news");
	_tmp1_ = service_get_reload_label ((Service*) self, _tmp0_);
	_g_object_unref0 (self->priv->reload);
	self->priv->reload = _tmp1_;
	_tmp2_ = self->priv->reload;
	clutter_actor_hide ((ClutterActor*) _tmp2_);
	_tmp3_ = shadowed_label_new ("");
	g_object_ref_sink (_tmp3_);
	_g_object_unref0 (self->priv->label_list);
	self->priv->label_list = _tmp3_;
	_tmp4_ = self->priv->label_list;
	clutter_actor_hide ((ClutterActor*) _tmp4_);
	_tmp5_ = self->priv->label_list;
	clutter_actor_set_reactive ((ClutterActor*) _tmp5_, TRUE);
	_tmp6_ = self->priv->label_list;
	g_signal_connect_object ((ClutterActor*) _tmp6_, "button-release-event", (GCallback) ___lambda14__clutter_actor_button_release_event, self, 0);
	_tmp7_ = g_settings_new ("org.pantheon.gazette.news");
	_g_object_unref0 (self->priv->settings);
	self->priv->settings = _tmp7_;
	_tmp8_ = self->priv->settings;
	g_signal_connect_object (_tmp8_, "changed", (GCallback) ___lambda15__g_settings_changed, self, 0);
	_tmp9_ = (SoupSessionAsync*) soup_session_async_new ();
	_g_object_unref0 (self->priv->session);
	self->priv->session = (SoupSession*) _tmp9_;
	service_load ((Service*) self);
	_tmp10_ = self->priv->settings;
	_tmp11_ = g_settings_get_int (_tmp10_, "update-interval");
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) _tmp11_, _service_update_gsource_func, g_object_ref ((Service*) self), g_object_unref);
	_tmp12_ = _ ("News");
	_tmp13_ = g_strdup_printf ("' font='20' face='Raleway'>%s</span>", _tmp12_);
	_tmp14_ = _tmp13_;
	_tmp15_ = g_strconcat ("<span color='" textcolor, _tmp14_, NULL);
	_tmp16_ = _tmp15_;
	_tmp17_ = shadowed_label_new (_tmp16_);
	g_object_ref_sink (_tmp17_);
	_tmp18_ = _tmp17_;
	_g_free0 (_tmp16_);
	_g_free0 (_tmp14_);
	label = _tmp18_;
	_tmp19_ = self->priv->label_list;
	_tmp20_ = clutter_actor_get_height ((ClutterActor*) label);
	_tmp21_ = _tmp20_;
	clutter_actor_set_y ((ClutterActor*) _tmp19_, _tmp21_ + 12);
	_tmp22_ = self->priv->label_list;
	clutter_actor_set_x ((ClutterActor*) _tmp22_, (gfloat) 12);
	_tmp23_ = self->priv->reload;
	_tmp24_ = self->priv->label_list;
	_tmp25_ = clutter_actor_get_y ((ClutterActor*) _tmp24_);
	_tmp26_ = _tmp25_;
	clutter_actor_set_y ((ClutterActor*) _tmp23_, _tmp26_);
	_tmp27_ = self->priv->reload;
	_tmp28_ = self->priv->label_list;
	_tmp29_ = clutter_actor_get_x ((ClutterActor*) _tmp28_);
	_tmp30_ = _tmp29_;
	clutter_actor_set_x ((ClutterActor*) _tmp27_, _tmp30_);
	clutter_actor_add_child ((ClutterActor*) self, (ClutterActor*) label);
	_tmp31_ = self->priv->reload;
	clutter_actor_add_child ((ClutterActor*) self, (ClutterActor*) _tmp31_);
	_tmp32_ = self->priv->label_list;
	clutter_actor_add_child ((ClutterActor*) self, (ClutterActor*) _tmp32_);
	_g_object_unref0 (label);
	return self;
}


News* news_new (void) {
	return news_construct (TYPE_NEWS);
}


static void news_real_create (Service* base) {
	News * self;
	self = (News*) base;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gint string_index_of (const gchar* self, const gchar* needle, gint start_index) {
	gint result = 0;
	gint _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _result_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = needle;
	_tmp2_ = strstr (((gchar*) self) + _tmp0_, (gchar*) _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* _tmp0_;
	glong _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* end;
	gchar* _tmp3_;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_;
		gchar* _tmp6_;
		_tmp5_ = end;
		_tmp6_ = str;
		result = (glong) (_tmp5_ - _tmp6_);
		return result;
	}
}


static gchar* string_substring (const gchar* self, glong offset, glong len) {
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp1_;
	gboolean _tmp3_;
	glong _tmp9_;
	glong _tmp15_;
	glong _tmp18_;
	glong _tmp19_;
	glong _tmp20_;
	glong _tmp21_;
	glong _tmp22_;
	gchar* _tmp23_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		glong _tmp4_;
		glong _tmp5_;
		glong _tmp6_ = 0L;
		_tmp4_ = offset;
		_tmp5_ = len;
		_tmp6_ = string_strnlen ((gchar*) self, _tmp4_ + _tmp5_);
		string_length = _tmp6_;
	} else {
		gint _tmp7_;
		gint _tmp8_;
		_tmp7_ = strlen (self);
		_tmp8_ = _tmp7_;
		string_length = (glong) _tmp8_;
	}
	_tmp9_ = offset;
	if (_tmp9_ < ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		glong _tmp12_;
		_tmp10_ = string_length;
		_tmp11_ = offset;
		offset = _tmp10_ + _tmp11_;
		_tmp12_ = offset;
		g_return_val_if_fail (_tmp12_ >= ((glong) 0), NULL);
	} else {
		glong _tmp13_;
		glong _tmp14_;
		_tmp13_ = offset;
		_tmp14_ = string_length;
		g_return_val_if_fail (_tmp13_ <= _tmp14_, NULL);
	}
	_tmp15_ = len;
	if (_tmp15_ < ((glong) 0)) {
		glong _tmp16_;
		glong _tmp17_;
		_tmp16_ = string_length;
		_tmp17_ = offset;
		len = _tmp16_ - _tmp17_;
	}
	_tmp18_ = offset;
	_tmp19_ = len;
	_tmp20_ = string_length;
	g_return_val_if_fail ((_tmp18_ + _tmp19_) <= _tmp20_, NULL);
	_tmp21_ = offset;
	_tmp22_ = len;
	_tmp23_ = g_strndup (((gchar*) self) + _tmp21_, (gsize) _tmp22_);
	result = _tmp23_;
	return result;
}


static void __lambda16_ (News* self, SoupSession* session, SoupMessage* m) {
	SoupMessage* _tmp0_;
	SoupMessageBody* _tmp1_;
	guint8* _tmp2_;
	gint _tmp2__length1;
	gchar* _tmp3_;
	gchar* output;
	const gchar* _tmp4_;
	const gchar* _tmp7_;
	gint _tmp8_ = 0;
	gint offset;
	NewsNews* _tmp9_ = NULL;
	gchar* _tmp42_;
	gchar* list;
	ShadowedLabel* _tmp56_;
	const gchar* _tmp57_;
	gchar* _tmp58_;
	gchar* _tmp59_;
	ShadowedLabel* _tmp60_;
	g_return_if_fail (session != NULL);
	g_return_if_fail (m != NULL);
	_tmp0_ = m;
	_tmp1_ = _tmp0_->response_body;
	_tmp2_ = _tmp1_->data;
	_tmp2__length1 = (gint) _tmp1_->length;
	_tmp3_ = g_strdup ((const gchar*) _tmp2_);
	output = _tmp3_;
	_tmp4_ = output;
	if (_tmp4_ == NULL) {
		ShadowedLabel* _tmp5_;
		ShadowedLabel* _tmp6_;
		_tmp5_ = self->priv->label_list;
		clutter_actor_hide ((ClutterActor*) _tmp5_);
		_tmp6_ = self->priv->reload;
		clutter_actor_show ((ClutterActor*) _tmp6_);
		_g_free0 (output);
		return;
	}
	_tmp7_ = output;
	_tmp8_ = string_index_of (_tmp7_, "<item>", 0);
	offset = _tmp8_;
	_tmp9_ = g_new0 (NewsNews, 10);
	self->priv->news = (_vala_NewsNews_array_free (self->priv->news, self->priv->news_length1), NULL);
	self->priv->news = _tmp9_;
	self->priv->news_length1 = 10;
	self->priv->_news_size_ = self->priv->news_length1;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp10_;
			_tmp10_ = TRUE;
			while (TRUE) {
				gboolean _tmp11_;
				gint _tmp13_;
				const gchar* _tmp14_;
				gint _tmp15_;
				gint _tmp16_ = 0;
				const gchar* _tmp17_;
				gint _tmp18_;
				const gchar* _tmp19_;
				gint _tmp20_;
				gint _tmp21_ = 0;
				gint _tmp22_;
				gchar* _tmp23_ = NULL;
				gchar* title;
				const gchar* _tmp24_;
				gint _tmp25_;
				gint _tmp26_ = 0;
				const gchar* _tmp27_;
				gint _tmp28_;
				const gchar* _tmp29_;
				gint _tmp30_;
				gint _tmp31_ = 0;
				gint _tmp32_;
				gchar* _tmp33_ = NULL;
				gchar* url;
				NewsNews* _tmp34_;
				gint _tmp34__length1;
				gint _tmp35_;
				const gchar* _tmp36_;
				gchar* _tmp37_ = NULL;
				const gchar* _tmp38_;
				gchar* _tmp39_;
				NewsNews _tmp40_ = {0};
				NewsNews _tmp41_;
				_tmp11_ = _tmp10_;
				if (!_tmp11_) {
					gint _tmp12_;
					_tmp12_ = i;
					i = _tmp12_ + 1;
				}
				_tmp10_ = FALSE;
				_tmp13_ = i;
				if (!(_tmp13_ < 10)) {
					break;
				}
				_tmp14_ = output;
				_tmp15_ = offset;
				_tmp16_ = string_index_of (_tmp14_, "<title>", _tmp15_);
				offset = _tmp16_ + 7;
				_tmp17_ = output;
				_tmp18_ = offset;
				_tmp19_ = output;
				_tmp20_ = offset;
				_tmp21_ = string_index_of (_tmp19_, "</title>", _tmp20_);
				_tmp22_ = offset;
				_tmp23_ = string_substring (_tmp17_, (glong) _tmp18_, (glong) (_tmp21_ - _tmp22_));
				title = _tmp23_;
				_tmp24_ = output;
				_tmp25_ = offset;
				_tmp26_ = string_index_of (_tmp24_, "<link>", _tmp25_);
				offset = _tmp26_ + 6;
				_tmp27_ = output;
				_tmp28_ = offset;
				_tmp29_ = output;
				_tmp30_ = offset;
				_tmp31_ = string_index_of (_tmp29_, "</link>", _tmp30_);
				_tmp32_ = offset;
				_tmp33_ = string_substring (_tmp27_, (glong) _tmp28_, (glong) (_tmp31_ - _tmp32_));
				url = _tmp33_;
				_tmp34_ = self->priv->news;
				_tmp34__length1 = self->priv->news_length1;
				_tmp35_ = i;
				_tmp36_ = title;
				_tmp37_ = service_ellipsize (_tmp36_, 40);
				_tmp38_ = url;
				_tmp39_ = g_strdup (_tmp38_);
				_g_free0 (_tmp40_.title);
				_tmp40_.title = _tmp37_;
				_g_free0 (_tmp40_.url);
				_tmp40_.url = _tmp39_;
				news_news_destroy (&_tmp34_[_tmp35_]);
				_tmp34_[_tmp35_] = _tmp40_;
				_tmp41_ = _tmp34_[_tmp35_];
				_g_free0 (url);
				_g_free0 (title);
			}
		}
	}
	_tmp42_ = g_strdup ("<span color='" textcolor "' font='12' face='Open Sans'>");
	list = _tmp42_;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp43_;
			_tmp43_ = TRUE;
			while (TRUE) {
				gboolean _tmp44_;
				gint _tmp46_;
				NewsNews* _tmp47_;
				gint _tmp47__length1;
				const gchar* _tmp48_;
				NewsNews* _tmp49_;
				gint _tmp49__length1;
				gint _tmp50_;
				NewsNews _tmp51_;
				const gchar* _tmp52_;
				gchar* _tmp53_;
				gchar* _tmp54_;
				gchar* _tmp55_;
				_tmp44_ = _tmp43_;
				if (!_tmp44_) {
					gint _tmp45_;
					_tmp45_ = i;
					i = _tmp45_ + 1;
				}
				_tmp43_ = FALSE;
				_tmp46_ = i;
				_tmp47_ = self->priv->news;
				_tmp47__length1 = self->priv->news_length1;
				if (!(_tmp46_ < _tmp47__length1)) {
					break;
				}
				_tmp48_ = list;
				_tmp49_ = self->priv->news;
				_tmp49__length1 = self->priv->news_length1;
				_tmp50_ = i;
				_tmp51_ = _tmp49_[_tmp50_];
				_tmp52_ = _tmp51_.title;
				_tmp53_ = g_strconcat (_tmp52_, "\n", NULL);
				_tmp54_ = _tmp53_;
				_tmp55_ = g_strconcat (_tmp48_, _tmp54_, NULL);
				_g_free0 (list);
				list = _tmp55_;
				_g_free0 (_tmp54_);
			}
		}
	}
	_tmp56_ = self->priv->label_list;
	_tmp57_ = list;
	_tmp58_ = g_strconcat (_tmp57_, "</span>", NULL);
	_tmp59_ = _tmp58_;
	shadowed_label_set_label (_tmp56_, _tmp59_);
	_g_free0 (_tmp59_);
	_tmp60_ = self->priv->label_list;
	clutter_actor_set_reactive ((ClutterActor*) _tmp60_, TRUE);
	_g_free0 (list);
	_g_free0 (output);
}


static void ___lambda16__soup_session_callback (SoupSession* session, SoupMessage* msg, gpointer self) {
	__lambda16_ (self, session, msg);
}


static gboolean news_real_update (Service* base) {
	News * self;
	gboolean result = FALSE;
	ShadowedLabel* _tmp0_;
	ShadowedLabel* _tmp1_;
	ShadowedLabel* _tmp2_;
	ShadowedLabel* _tmp3_;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	GSettings* _tmp9_;
	gchar* _tmp10_ = NULL;
	gchar* soup_url;
	SoupMessage* _tmp11_;
	SoupSession* _tmp12_;
	SoupMessage* _tmp13_;
	SoupMessage* _tmp14_;
	self = (News*) base;
	g_debug ("News.vala:56: Updating News");
	_tmp0_ = self->priv->reload;
	clutter_actor_hide ((ClutterActor*) _tmp0_);
	_tmp1_ = self->priv->label_list;
	clutter_actor_set_reactive ((ClutterActor*) _tmp1_, FALSE);
	_tmp2_ = self->priv->label_list;
	clutter_actor_show ((ClutterActor*) _tmp2_);
	_tmp3_ = self->priv->label_list;
	_tmp4_ = _ ("Loading news,\nplease wait.");
	_tmp5_ = g_strconcat ("<span color='" textcolor "' face='Open Sans Light' font='16'>", _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	_tmp7_ = g_strconcat (_tmp6_, "</span>", NULL);
	_tmp8_ = _tmp7_;
	shadowed_label_set_label (_tmp3_, _tmp8_);
	_g_free0 (_tmp8_);
	_g_free0 (_tmp6_);
	_tmp9_ = self->priv->settings;
	_tmp10_ = g_settings_get_string (_tmp9_, "rss-url");
	soup_url = _tmp10_;
	_tmp11_ = soup_message_new ("GET", soup_url);
	_g_object_unref0 (self->priv->message);
	self->priv->message = _tmp11_;
	_tmp12_ = self->priv->session;
	_tmp13_ = self->priv->message;
	_tmp14_ = _g_object_ref0 (_tmp13_);
	soup_session_queue_message (_tmp12_, _tmp14_, ___lambda16__soup_session_callback, self);
	result = TRUE;
	_g_free0 (soup_url);
	return result;
}


static void news_news_copy (const NewsNews* self, NewsNews* dest) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	_tmp0_ = (*self).title;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 ((*dest).title);
	(*dest).title = _tmp1_;
	_tmp2_ = (*self).url;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 ((*dest).url);
	(*dest).url = _tmp3_;
}


static void news_news_destroy (NewsNews* self) {
	_g_free0 ((*self).title);
	_g_free0 ((*self).url);
}


static NewsNews* news_news_dup (const NewsNews* self) {
	NewsNews* dup;
	dup = g_new0 (NewsNews, 1);
	news_news_copy (self, dup);
	return dup;
}


static void news_news_free (NewsNews* self) {
	news_news_destroy (self);
	g_free (self);
}


static GType news_news_get_type (void) {
	static volatile gsize news_news_type_id__volatile = 0;
	if (g_once_init_enter (&news_news_type_id__volatile)) {
		GType news_news_type_id;
		news_news_type_id = g_boxed_type_register_static ("NewsNews", (GBoxedCopyFunc) news_news_dup, (GBoxedFreeFunc) news_news_free);
		g_once_init_leave (&news_news_type_id__volatile, news_news_type_id);
	}
	return news_news_type_id__volatile;
}


static void news_class_init (NewsClass * klass) {
	news_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (NewsPrivate));
	SERVICE_CLASS (klass)->create = news_real_create;
	SERVICE_CLASS (klass)->update = news_real_update;
	G_OBJECT_CLASS (klass)->finalize = news_finalize;
}


static void news_instance_init (News * self) {
	self->priv = NEWS_GET_PRIVATE (self);
}


static void news_finalize (GObject* obj) {
	News * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_NEWS, News);
	_g_object_unref0 (self->priv->settings);
	_g_object_unref0 (self->priv->session);
	_g_object_unref0 (self->priv->message);
	_g_object_unref0 (self->priv->label_list);
	_g_object_unref0 (self->priv->reload);
	self->priv->news = (_vala_NewsNews_array_free (self->priv->news, self->priv->news_length1), NULL);
	G_OBJECT_CLASS (news_parent_class)->finalize (obj);
}


GType news_get_type (void) {
	static volatile gsize news_type_id__volatile = 0;
	if (g_once_init_enter (&news_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (NewsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) news_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (News), 0, (GInstanceInitFunc) news_instance_init, NULL };
		GType news_type_id;
		news_type_id = g_type_register_static (TYPE_SERVICE, "News", &g_define_type_info, 0);
		g_once_init_leave (&news_type_id__volatile, news_type_id);
	}
	return news_type_id__volatile;
}



