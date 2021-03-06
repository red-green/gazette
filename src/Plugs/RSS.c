/* RSS.c generated by valac 0.20.1, the Vala compiler
 * generated from RSS.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>


#define GAZETTE_TYPE_SERVICE (gazette_service_get_type ())
#define GAZETTE_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GAZETTE_TYPE_SERVICE, GazetteService))
#define GAZETTE_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GAZETTE_TYPE_SERVICE, GazetteServiceClass))
#define GAZETTE_IS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GAZETTE_TYPE_SERVICE))
#define GAZETTE_IS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GAZETTE_TYPE_SERVICE))
#define GAZETTE_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GAZETTE_TYPE_SERVICE, GazetteServiceClass))

typedef struct _GazetteService GazetteService;
typedef struct _GazetteServiceClass GazetteServiceClass;
typedef struct _GazetteServicePrivate GazetteServicePrivate;

#define GAZETTE_TYPE_RSS (gazette_rss_get_type ())
#define GAZETTE_RSS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GAZETTE_TYPE_RSS, GazetteRSS))
#define GAZETTE_RSS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GAZETTE_TYPE_RSS, GazetteRSSClass))
#define GAZETTE_IS_RSS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GAZETTE_TYPE_RSS))
#define GAZETTE_IS_RSS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GAZETTE_TYPE_RSS))
#define GAZETTE_RSS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GAZETTE_TYPE_RSS, GazetteRSSClass))

typedef struct _GazetteRSS GazetteRSS;
typedef struct _GazetteRSSClass GazetteRSSClass;
typedef struct _GazetteRSSPrivate GazetteRSSPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block2Data Block2Data;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _GazetteService {
	GObject parent_instance;
	GazetteServicePrivate * priv;
	GtkGrid* container;
	GtkEventBox* item;
	GtkImage* icon;
	GtkSwitch* toggle;
	GtkLabel* name;
};

struct _GazetteServiceClass {
	GObjectClass parent_class;
	void (*run) (GazetteService* self, GFile* file);
};

struct _GazetteRSS {
	GazetteService parent_instance;
	GazetteRSSPrivate * priv;
	gchar* rss_url;
	gint update_interval;
};

struct _GazetteRSSClass {
	GazetteServiceClass parent_class;
};

struct _GazetteRSSPrivate {
	GSettings* settings;
};

struct _Block2Data {
	int _ref_count_;
	GazetteRSS * self;
	GtkEntry* rssEntry;
	GtkScale* scale;
};


static gpointer gazette_rss_parent_class = NULL;

GType gazette_service_get_type (void) G_GNUC_CONST;
GType gazette_rss_get_type (void) G_GNUC_CONST;
#define GAZETTE_RSS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GAZETTE_TYPE_RSS, GazetteRSSPrivate))
enum  {
	GAZETTE_RSS_DUMMY_PROPERTY
};
GazetteRSS* gazette_rss_new (void);
GazetteRSS* gazette_rss_construct (GType object_type);
static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (void * _userdata_);
GazetteService* gazette_service_new (const gchar* name, const gchar* icon);
GazetteService* gazette_service_construct (GType object_type, const gchar* name, const gchar* icon);
static void __lambda6_ (Block2Data* _data2_);
static void ___lambda6__gtk_editable_changed (GtkEditable* _sender, gpointer self);
static void __lambda7_ (Block2Data* _data2_);
static void ___lambda7__gtk_range_value_changed (GtkRange* _sender, gpointer self);
static void __lambda8_ (Block2Data* _data2_);
static void ___lambda8__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void gazette_rss_real_run (GazetteService* base, GFile* file);
static void gazette_rss_finalize (GObject* obj);


static Block2Data* block2_data_ref (Block2Data* _data2_) {
	g_atomic_int_inc (&_data2_->_ref_count_);
	return _data2_;
}


static void block2_data_unref (void * _userdata_) {
	Block2Data* _data2_;
	_data2_ = (Block2Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
		GazetteRSS * self;
		self = _data2_->self;
		_g_object_unref0 (_data2_->scale);
		_g_object_unref0 (_data2_->rssEntry);
		_g_object_unref0 (self);
		g_slice_free (Block2Data, _data2_);
	}
}


static void __lambda6_ (Block2Data* _data2_) {
	GazetteRSS * self;
	GSettings* _tmp0_;
	const gchar* _tmp1_ = NULL;
	self = _data2_->self;
	_tmp0_ = self->priv->settings;
	_tmp1_ = gtk_entry_get_text (_data2_->rssEntry);
	g_settings_set_string (_tmp0_, "rss-url", _tmp1_);
}


static void ___lambda6__gtk_editable_changed (GtkEditable* _sender, gpointer self) {
	__lambda6_ (self);
}


static void __lambda7_ (Block2Data* _data2_) {
	GazetteRSS * self;
	GSettings* _tmp0_;
	gdouble _tmp1_ = 0.0;
	self = _data2_->self;
	_tmp0_ = self->priv->settings;
	_tmp1_ = gtk_range_get_value ((GtkRange*) _data2_->scale);
	g_settings_set_int (_tmp0_, "update-interval", (gint) _tmp1_);
}


static void ___lambda7__gtk_range_value_changed (GtkRange* _sender, gpointer self) {
	__lambda7_ (self);
}


static void __lambda8_ (Block2Data* _data2_) {
	GazetteRSS * self;
	GSettings* _tmp0_;
	GSettings* _tmp1_;
	GSettings* _tmp2_;
	gchar* _tmp3_ = NULL;
	GSettings* _tmp4_;
	gint _tmp5_ = 0;
	const gchar* _tmp6_;
	gint _tmp7_;
	self = _data2_->self;
	_tmp0_ = self->priv->settings;
	g_settings_reset (_tmp0_, "rss-url");
	_tmp1_ = self->priv->settings;
	g_settings_reset (_tmp1_, "update-interval");
	_tmp2_ = self->priv->settings;
	_tmp3_ = g_settings_get_string (_tmp2_, "rss-url");
	_g_free0 (self->rss_url);
	self->rss_url = _tmp3_;
	_tmp4_ = self->priv->settings;
	_tmp5_ = g_settings_get_int (_tmp4_, "update-interval");
	self->update_interval = _tmp5_;
	_tmp6_ = self->rss_url;
	gtk_entry_set_text (_data2_->rssEntry, _tmp6_);
	_tmp7_ = self->update_interval;
	gtk_range_set_value ((GtkRange*) _data2_->scale, (gdouble) _tmp7_);
}


static void ___lambda8__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda8_ (self);
}


GazetteRSS* gazette_rss_construct (GType object_type) {
	GazetteRSS * self = NULL;
	Block2Data* _data2_;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gchar* _tmp2_;
	GSettings* _tmp3_;
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_;
	gchar* _tmp13_;
	GtkLabel* _tmp14_;
	GtkLabel* _tmp15_;
	GtkLabel* rssLabel;
	GtkGrid* _tmp16_;
	GtkEntry* _tmp17_;
	const gchar* _tmp18_;
	GtkGrid* _tmp19_;
	const gchar* _tmp20_ = NULL;
	gchar* _tmp21_;
	gchar* _tmp22_;
	GtkLabel* _tmp23_;
	GtkLabel* _tmp24_;
	GtkLabel* refreshLabel;
	GtkGrid* _tmp25_;
	GtkScale* _tmp26_;
	const gchar* _tmp27_ = NULL;
	const gchar* _tmp28_ = NULL;
	const gchar* _tmp29_ = NULL;
	const gchar* _tmp30_ = NULL;
	gint _tmp31_;
	GtkGrid* _tmp32_;
	const gchar* _tmp33_ = NULL;
	GtkButton* _tmp34_;
	GtkButton* resetButton;
	GtkGrid* _tmp35_;
	GError * _inner_error_ = NULL;
	_data2_ = g_slice_new0 (Block2Data);
	_data2_->_ref_count_ = 1;
	_tmp0_ = _ ("News");
	_tmp1_ = g_strconcat ("RSS ", _tmp0_, NULL);
	_tmp2_ = _tmp1_;
	self = (GazetteRSS*) gazette_service_construct (object_type, _tmp2_, "internet-news-reader");
	_data2_->self = g_object_ref (self);
	_g_free0 (_tmp2_);
	_tmp3_ = g_settings_new ("org.pantheon.gazette.news");
	_g_object_unref0 (self->priv->settings);
	self->priv->settings = _tmp3_;
	{
		GSettings* _tmp4_;
		gchar* _tmp5_ = NULL;
		GSettings* _tmp6_;
		gint _tmp7_ = 0;
		_tmp4_ = self->priv->settings;
		_tmp5_ = g_settings_get_string (_tmp4_, "rss-url");
		_g_free0 (self->rss_url);
		self->rss_url = _tmp5_;
		_tmp6_ = self->priv->settings;
		_tmp7_ = g_settings_get_int (_tmp6_, "update-interval");
		self->update_interval = _tmp7_;
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FILE* _tmp8_;
		GError* _tmp9_;
		const gchar* _tmp10_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp8_ = stderr;
		_tmp9_ = e;
		_tmp10_ = _tmp9_->message;
		fprintf (_tmp8_, "Unable to find settings: %s\n", _tmp10_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		block2_data_unref (_data2_);
		_data2_ = NULL;
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp11_ = _ ("URL");
	_tmp12_ = g_strconcat (_tmp11_, " :", NULL);
	_tmp13_ = _tmp12_;
	_tmp14_ = (GtkLabel*) gtk_label_new (_tmp13_);
	g_object_ref_sink (_tmp14_);
	_tmp15_ = _tmp14_;
	_g_free0 (_tmp13_);
	rssLabel = _tmp15_;
	_tmp16_ = ((GazetteService*) self)->container;
	gtk_grid_attach (_tmp16_, (GtkWidget*) rssLabel, 0, 0, 1, 1);
	gtk_misc_set_alignment ((GtkMisc*) rssLabel, (gfloat) 1, (gfloat) 0);
	_tmp17_ = (GtkEntry*) gtk_entry_new ();
	g_object_ref_sink (_tmp17_);
	_data2_->rssEntry = _tmp17_;
	_tmp18_ = self->rss_url;
	gtk_entry_set_text (_data2_->rssEntry, _tmp18_);
	_tmp19_ = ((GazetteService*) self)->container;
	gtk_grid_attach (_tmp19_, (GtkWidget*) _data2_->rssEntry, 1, 0, 2, 1);
	g_signal_connect_data ((GtkEditable*) _data2_->rssEntry, "changed", (GCallback) ___lambda6__gtk_editable_changed, block2_data_ref (_data2_), (GClosureNotify) block2_data_unref, 0);
	_tmp20_ = _ ("Refresh Interval");
	_tmp21_ = g_strconcat (_tmp20_, " :", NULL);
	_tmp22_ = _tmp21_;
	_tmp23_ = (GtkLabel*) gtk_label_new (_tmp22_);
	g_object_ref_sink (_tmp23_);
	_tmp24_ = _tmp23_;
	_g_free0 (_tmp22_);
	refreshLabel = _tmp24_;
	_tmp25_ = ((GazetteService*) self)->container;
	gtk_grid_attach (_tmp25_, (GtkWidget*) refreshLabel, 0, 1, 1, 1);
	gtk_misc_set_alignment ((GtkMisc*) refreshLabel, (gfloat) 1, (gfloat) 0);
	_tmp26_ = (GtkScale*) gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, (gdouble) 0, (gdouble) 3600000, (gdouble) 60000);
	g_object_ref_sink (_tmp26_);
	_data2_->scale = _tmp26_;
	gtk_scale_set_draw_value (_data2_->scale, FALSE);
	_tmp27_ = _ ("5 min");
	gtk_scale_add_mark (_data2_->scale, (gdouble) 300000, GTK_POS_BOTTOM, _tmp27_);
	_tmp28_ = _ ("20 min");
	gtk_scale_add_mark (_data2_->scale, (gdouble) 1200000, GTK_POS_BOTTOM, _tmp28_);
	_tmp29_ = _ ("40 min");
	gtk_scale_add_mark (_data2_->scale, (gdouble) 2400000, GTK_POS_BOTTOM, _tmp29_);
	_tmp30_ = _ ("1 hour");
	gtk_scale_add_mark (_data2_->scale, (gdouble) 3600000, GTK_POS_BOTTOM, _tmp30_);
	_tmp31_ = self->update_interval;
	gtk_range_set_value ((GtkRange*) _data2_->scale, (gdouble) _tmp31_);
	g_signal_connect_data ((GtkRange*) _data2_->scale, "value-changed", (GCallback) ___lambda7__gtk_range_value_changed, block2_data_ref (_data2_), (GClosureNotify) block2_data_unref, 0);
	_tmp32_ = ((GazetteService*) self)->container;
	gtk_grid_attach (_tmp32_, (GtkWidget*) _data2_->scale, 1, 1, 2, 1);
	_tmp33_ = _ ("Reset");
	_tmp34_ = (GtkButton*) gtk_button_new_with_label (_tmp33_);
	g_object_ref_sink (_tmp34_);
	resetButton = _tmp34_;
	_tmp35_ = ((GazetteService*) self)->container;
	gtk_grid_attach (_tmp35_, (GtkWidget*) resetButton, 2, 2, 1, 1);
	g_signal_connect_data (resetButton, "clicked", (GCallback) ___lambda8__gtk_button_clicked, block2_data_ref (_data2_), (GClosureNotify) block2_data_unref, 0);
	_g_object_unref0 (resetButton);
	_g_object_unref0 (refreshLabel);
	_g_object_unref0 (rssLabel);
	block2_data_unref (_data2_);
	_data2_ = NULL;
	return self;
}


GazetteRSS* gazette_rss_new (void) {
	return gazette_rss_construct (GAZETTE_TYPE_RSS);
}


static void gazette_rss_real_run (GazetteService* base, GFile* file) {
	GazetteRSS * self;
	self = (GazetteRSS*) base;
	g_return_if_fail (file != NULL);
}


static void gazette_rss_class_init (GazetteRSSClass * klass) {
	gazette_rss_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (GazetteRSSPrivate));
	GAZETTE_SERVICE_CLASS (klass)->run = gazette_rss_real_run;
	G_OBJECT_CLASS (klass)->finalize = gazette_rss_finalize;
}


static void gazette_rss_instance_init (GazetteRSS * self) {
	gchar* _tmp0_;
	self->priv = GAZETTE_RSS_GET_PRIVATE (self);
	_tmp0_ = g_strdup ("");
	self->rss_url = _tmp0_;
	self->update_interval = 0;
}


static void gazette_rss_finalize (GObject* obj) {
	GazetteRSS * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GAZETTE_TYPE_RSS, GazetteRSS);
	_g_free0 (self->rss_url);
	_g_object_unref0 (self->priv->settings);
	G_OBJECT_CLASS (gazette_rss_parent_class)->finalize (obj);
}


GType gazette_rss_get_type (void) {
	static volatile gsize gazette_rss_type_id__volatile = 0;
	if (g_once_init_enter (&gazette_rss_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GazetteRSSClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gazette_rss_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GazetteRSS), 0, (GInstanceInitFunc) gazette_rss_instance_init, NULL };
		GType gazette_rss_type_id;
		gazette_rss_type_id = g_type_register_static (GAZETTE_TYPE_SERVICE, "GazetteRSS", &g_define_type_info, 0);
		g_once_init_leave (&gazette_rss_type_id__volatile, gazette_rss_type_id);
	}
	return gazette_rss_type_id__volatile;
}



