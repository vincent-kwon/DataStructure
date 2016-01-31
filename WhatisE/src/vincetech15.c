#include "main.h"
#include "vincetech15.h"

/*
 * 1. how to change naviframe color (not default theme)
 * 2. how to layout naviframe header?
 * 3. how to animate small sub-menu from left to right?
 * 4. how to create genlist cells (image background for each cell)
 * 5. how to how to set % height for each item
 * 6. how to set attributes width, height, padding, margin
 */
static void
win_delete_request_cb(void *data, Evas_Object *obj, void *event_info)
{
	ui_app_exit();
}

static void
list_selected_cb(void *data, Evas_Object *obj, void *event_info)
{
	Elm_Object_Item *it = event_info;
	elm_list_item_selected_set(it, EINA_FALSE);
}

static Eina_Bool
naviframe_pop_cb(void *data, Elm_Object_Item *it)
{
	ui_app_exit();
	return EINA_FALSE;
}

void list_event_cb(void *data, Evas_Object *obj, void *event_info) {

}

static void my_table_pack(Evas_Object *table, Evas_Object *child, int x, int y, int w, int h)
{
	evas_object_size_hint_align_set(child, EVAS_HINT_FILL, EVAS_HINT_FILL);
	evas_object_size_hint_weight_set(child, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_table_pack(table, child, x, y, w, h);
	evas_object_show(child);
}

static void my_box_pack(Evas_Object *box, Evas_Object *child, double h_weight, double v_weight, double h_align, double v_align)
{
	/* create a frame we shall use as padding around the child widget */
	Evas_Object *frame = elm_frame_add(box);
	/* use the medium padding style. there is "pad_small", "pad_medium",
	* "pad_large" and "pad_huge" available as styles in addition to the
	* "default" frame style */
	elm_object_style_set(frame, "pad_small"); // this reduces gap
	/* set the input weight/aling on the frame instead of the childll */
	evas_object_size_hint_weight_set(frame, h_weight, v_weight);
	evas_object_size_hint_align_set(frame, h_align, v_align);
	{
		/* tell the child that is packed into the frame to be able to expand */
		evas_object_size_hint_weight_set(child, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
		/* fill the expanded area (above) as opposaed to center in it */
		evas_object_size_hint_align_set(child, EVAS_HINT_FILL, EVAS_HINT_FILL);
		/* actually put the child in the f
		rame and show it */
		evas_object_show(child);
		elm_object_content_set(frame, child);
	}
	/* put the frame into the box instead of the child directly */
	elm_box_pack_end(box, frame);
	/* show the frame */
	evas_object_show(frame);
}

static void
app_get_resource(const char *res_file_in, char *res_path_out, int res_path_max)
{
	char *res_path = app_get_resource_path();
	if (res_path) {
		snprintf(res_path_out, res_path_max, "%s%s", res_path, res_file_in);
		free(res_path);
	}
}

static void
create_list_view(appdata_s *ad)
{
	Evas_Object *list, *btn, *btn1, *btn2, *btn3, *btn4, *btn5, *image, *box, *boxInner1, *boxInner2, *table, *bg;
	Evas_Object *nf = ad->nf;
	Evas_Object* label1, *entry1;
	Elm_Object_Item *nf_it;
	char buf[100] = { 0, };
    box = elm_box_add(nf);

	/* List */
	list = elm_list_add(nf);
	elm_list_mode_set(list, ELM_LIST_COMPRESS);
	evas_object_smart_callback_add(list, "selected", list_selected_cb, NULL);

	/* Main Menu Items Here */
	elm_list_item_append(list, "Accessibility", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Bg", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Button", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Calendar", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Check", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Colorselector", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Ctxpopup", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Datetime", NULL, NULL, list_event_cb, ad);
	elm_list_item_append(list, "Entry", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Fastscroll", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Flipselector", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Gengrid", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Genlist", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Handler", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Hoversel", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Indicator", NULL, NULL, list_event_cb, ad);
	elm_list_item_append(list, "Label", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Multibuttonentry", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Naviframe", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Nocontents", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Pagecontrol", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Popup", NULL, NULL, list_event_cb, ad);
	elm_list_item_append(list, "Progressbar", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Radio", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Slider", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Spinner", NULL, NULL, list_event_cb, nf);
	elm_list_item_append(list, "Toolbar", NULL, NULL, list_event_cb, nf);

	elm_list_go(list);

	snprintf(buf, 100, "Whatis?");

	/* Floating Button 2 */
	//btn = elm_button_add(ad->nf);
	//elm_object_text_set(btn, "WHAT?");
	//image = elm_image_add(ad->nf);
	//evas_object_show(image);

	/* Add table with two buttons */
	/*
	 * 1 2 8
	 * 2 4 6
	 * 3 4 6
	 * 4 8
	 * 5 8
	 */

	/* Table */
	table = elm_table_add(ad->nf);
	bg = elm_bg_add(ad->nf);
	elm_bg_color_set(bg, 255,255,255);
	my_table_pack(table, bg, 0, 0, 10, 5);
	elm_table_homogeneous_set(table, EINA_TRUE);
	elm_table_padding_set(table, 1 * elm_config_scale_get(), 1 * elm_config_scale_get());
	evas_object_size_hint_weight_set(table, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(table, EVAS_HINT_FILL, EVAS_HINT_FILL);

	// 2-8
	char filePath2[PATH_MAX];
	bg = elm_bg_add(ad->nf);
	app_get_resource("images/vector-brain-icon.jpg", filePath2, PATH_MAX);
	dlog_print(DLOG_ERROR, LOG_TAG, "%s", filePath2);
	elm_bg_option_set(bg, ELM_BG_OPTION_LAST);
	elm_bg_file_set(bg, filePath2, NULL);
	my_table_pack(table, bg, 0, 0, 1, 1);

	box = elm_box_add(ad->nf);
	label1 = elm_label_add(ad->nf);
	elm_object_text_set(label1, "Add What You Want to Keep");
	my_box_pack(box, label1, EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, 1);
	my_table_pack(table, box, 1, 0, 9, 1);

	// 4-6
	label1 = elm_label_add(ad->nf);
	elm_object_text_set(label1, "Hint:");
	my_table_pack(table, label1, 0, 1, 4, 1);

	bg = elm_bg_add(ad->nf);
	elm_bg_color_set(bg, 255, 255, 255);

	my_table_pack(table, bg, 5, 1, 6, 1);
	elm_bg_color_set(bg, 255, 255, 255);

	entry1 = elm_entry_add(ad->nf);
	elm_object_text_set(entry1, "Vince Carter:");
	my_table_pack(table, entry1, 5, 1, 6, 1);

	// 4-6
	label1 = elm_label_add(ad->nf);
	elm_object_text_set(label1, "Message:");
	my_table_pack(table, label1, 0, 2, 4, 1);

	bg = elm_bg_add(ad->nf);
	elm_bg_color_set(bg, 255, 255, 255);

	my_table_pack(table, bg, 5, 2, 6, 1);
	elm_bg_color_set(bg, 255, 255, 255);

	entry1 = elm_entry_add(ad->nf);
	elm_object_text_set(entry1, "GOOGLE2015:");
	my_table_pack(table, entry1, 5, 2, 6, 1);
	my_box_pack(box, table, EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, 1);
	evas_object_show(table);

#if 0
	/* two inner boxes */
	boxInner1 = elm_box_add(box);
	boxInner2 = elm_box_add(box);

	elm_box_padding_set(boxInner1, ELM_SCALE_SIZE(10), ELM_SCALE_SIZE(10));
	elm_box_padding_set(boxInner2, ELM_SCALE_SIZE(1), ELM_SCALE_SIZE(1));

	evas_object_show(boxInner1);
	evas_object_show(boxInner2);

	char filePath[PATH_MAX];
	app_get_resource("tizen.png", filePath, PATH_MAX);

	dlog_print(DLOG_ERROR, LOG_TAG, "%s", filePath);

	elm_image_file_set(image, filePath, NULL);
	// below seems not working
	elm_object_part_content_set(btn, "icon", image);

	evas_object_show(btn);
	evas_object_show(list);
	evas_object_show(box);

	btn1 = elm_button_add(ad->nf);
	elm_object_text_set(btn1, "Who?");
	evas_object_show(btn1);


	btn2 = elm_button_add(ad->nf);
	elm_object_text_set(btn2, "When?");
	evas_object_show(btn2);


	btn3 = elm_button_add(ad->nf);
	elm_object_text_set(btn3, "Where?");
	evas_object_show(btn3);


	btn4 = elm_button_add(ad->nf);
	elm_object_text_set(btn4, "Why?");
	evas_object_show(btn4);


	btn5 = elm_button_add(ad->nf);
	elm_object_text_set(btn5, "How?");
	evas_object_show(btn5);
#endif

	// right search button
	//my_box_pack(box,table,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
	my_box_pack(box,list,EVAS_HINT_EXPAND, EVAS_HINT_EXPAND, EVAS_HINT_FILL, EVAS_HINT_FILL);
#if 0
	my_box_pack(boxInner1,btn1 ,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
	my_box_pack(boxInner1,btn2,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
	my_box_pack(boxInner2,btn3,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
	my_box_pack(boxInner2,btn4,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
	my_box_pack(boxInner2,btn5,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);

	my_box_pack(box,boxInner1,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
	my_box_pack(box,boxInner2,EVAS_HINT_EXPAND, 0, EVAS_HINT_FILL, EVAS_HINT_FILL);
#endif

	nf_it = elm_naviframe_item_push(nf, buf, NULL, NULL, box, NULL);
	elm_naviframe_item_pop_cb_set(nf_it, naviframe_pop_cb, ad->win);
}



static void
create_base_gui(appdata_s *ad)
{
	/*
	 * Widget Tree
	 * Window
	 *  - conform
	 *   - layout main
	 *    - naviframe */

	Evas_Object *btn, *image;

	/* Window */
	ad->win = elm_win_util_standard_add(PACKAGE, PACKAGE);
	elm_win_conformant_set(ad->win, EINA_TRUE);
	elm_win_autodel_set(ad->win, EINA_TRUE);

	if (elm_win_wm_rotation_supported_get(ad->win)) {
		int rots[4] = { 0, 90, 180, 270 };
		elm_win_wm_rotation_available_rotations_set(ad->win, (const int *)(&rots), 4);
	}

	evas_object_smart_callback_add(ad->win, "delete,request", win_delete_request_cb, NULL);

	/* Conformant */
	ad->conform = elm_conformant_add(ad->win);
	evas_object_size_hint_weight_set(ad->conform, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(ad->win, ad->conform);
	evas_object_show(ad->conform);

	/* Indicator */
	elm_win_indicator_mode_set(ad->win, ELM_WIN_INDICATOR_SHOW);
	elm_win_indicator_opacity_set(ad->win, ELM_WIN_INDICATOR_TRANSPARENT);

	/* Base Layout */
	ad->layout = elm_layout_add(ad->conform);
	evas_object_size_hint_weight_set(ad->layout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);

	// set a theme to layout
	elm_layout_theme_set(ad->layout, "layout", "application", "default");
	evas_object_show(ad->layout);

	// add a layout to conformant
	elm_object_content_set(ad->conform, ad->layout);

	/* Naviframe */
	ad->nf = elm_naviframe_add(ad->layout);
	/* Push a previous button to naviframe item automatically */
	elm_naviframe_prev_btn_auto_pushed_set(ad->nf, EINA_TRUE);
	create_list_view(ad);

	// a layout which added to conformant has content naviframe
	elm_object_part_content_set(ad->layout, "elm.swallow.content", ad->nf);

	eext_object_event_callback_add(ad->nf, EEXT_CALLBACK_BACK, eext_naviframe_back_cb, NULL);
	eext_object_event_callback_add(ad->nf, EEXT_CALLBACK_MORE, eext_naviframe_more_cb, NULL);

	/* Show window after base gui is set up */
	evas_object_show(ad->win);
}

static bool
app_create(void *data)
{
	/* Hook to take necessary actions before main event loop starts
		Initialize UI resources and application's data
		If this function returns true, the main loop of application starts
		If this function returns false, the application is terminated */
	appdata_s *ad = data;

	create_base_gui(ad);

	return true;
}

static void
app_control(app_control_h app_control, void *data)
{
	/* Handle the launch request. */
}

static void
app_pause(void *data)
{
	/* Take necessary actions when application becomes invisible. */
}

static void
app_resume(void *data)
{
	/* Take necessary actions when application becomes visible. */
}

static void
app_terminate(void *data)
{
	/* Release all resources. */
}

static void
ui_app_lang_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LANGUAGE_CHANGED*/
	char *locale = NULL;
	system_settings_get_value_string(SYSTEM_SETTINGS_KEY_LOCALE_LANGUAGE, &locale);
	elm_language_set(locale);
	free(locale);
	return;
}

static void
ui_app_orient_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_DEVICE_ORIENTATION_CHANGED*/
	return;
}

static void
ui_app_region_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_REGION_FORMAT_CHANGED*/
}

static void
ui_app_low_battery(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_BATTERY*/
}

static void
ui_app_low_memory(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_MEMORY*/
}

int
main(int argc, char *argv[])
{
	appdata_s ad = {0,};
	int ret = 0;

	ui_app_lifecycle_callback_s event_callback = {0,};
	app_event_handler_h handlers[5] = {NULL, };

	event_callback.create = app_create;
	event_callback.terminate = app_terminate;
	event_callback.pause = app_pause;
	event_callback.resume = app_resume;
	event_callback.app_control = app_control;

	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_BATTERY], APP_EVENT_LOW_BATTERY, ui_app_low_battery, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_MEMORY], APP_EVENT_LOW_MEMORY, ui_app_low_memory, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_DEVICE_ORIENTATION_CHANGED], APP_EVENT_DEVICE_ORIENTATION_CHANGED, ui_app_orient_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LANGUAGE_CHANGED], APP_EVENT_LANGUAGE_CHANGED, ui_app_lang_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_REGION_FORMAT_CHANGED], APP_EVENT_REGION_FORMAT_CHANGED, ui_app_region_changed, &ad);
	ui_app_remove_event_handler(handlers[APP_EVENT_LOW_MEMORY]);

	ret = ui_app_main(argc, argv, &event_callback, &ad);
	if (ret != APP_ERROR_NONE) {
		dlog_print(DLOG_ERROR, LOG_TAG, "app_main() is failed. err = %d", ret);
	}

	return ret;
}
