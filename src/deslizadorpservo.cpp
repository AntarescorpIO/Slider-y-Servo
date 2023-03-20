/**
 * @file slideryservo.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "../lvgl.h"
#include "ESP32Servo.h"
#include "deslizadoryservo.h"
#define Servo1 17 
static lv_obj_t * label ;
static lv_obj_t * label1;

static lv_style_t style1;

Servo servo1;
static void slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
//este segmento es lo que puede ocurrir mientras ocurre el evento slider o lo que es lo mismo no dejan de move la barra desplazadora
/*Refresh the text*/
 
  lv_label_set_text_fmt(label,"%"LV_PRId32, lv_slider_get_value(slider));
  int32_t pos =lv_slider_get_value(slider);
  lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);  /*Align top of the slider*/



    //moviendo un servo motor con un slider
    servo1.write(pos); 
 
}

/**
 * Create a slider and write its value on a label.
 */
 void deslisyservo()
{
    /*Create a slider in the center of the display*/
    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider, 0 , 200);
    lv_obj_set_width(slider, 500);  
    lv_obj_set_height(slider,30);                        /*Set the width*/
    lv_obj_center(slider);  
    //lv_obj_align(slider, LV_ALIGN_BOTTOM_MID, 0, 0);  /*esta es otra manera de posicionar un objeto creado*/
    lv_obj_set_pos(slider, 20,10);   /*Aqui es donde le damos la posicion al*/
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);  /*Assign an event function*/

    /*Create a label above the slider*/
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "0");
    lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15);    /*Align top of the slider*/




    label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "Desde Iztapalapa para el mundo");
    lv_obj_align_to(label1,slider, LV_ALIGN_BOTTOM_MID, 0, 20);  
  servo1.attach(Servo1,DEFAULT_uS_LOW,DEFAULT_uS_HIGH );

}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
/**********************
 *   STATIC FUNCTIONS
 **********************/




