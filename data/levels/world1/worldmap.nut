
import("/levels/preload_worldselect.nut");

fade_time <- 0.35;

// ============================================================================
//   AMBIENT LIGHT
// ============================================================================

if("ambient_r" in state && "ambient_g" in state && "ambient_b" in state){
  worldmap.settings.fade_to_ambient_light(state.ambient_r,
                                          state.ambient_g,
                                          state.ambient_b,
                                          0);
}

// ============================================================================
//   UNDERGROUND
// ============================================================================

if(! ("underground" in state)){
	state.underground <- false;
  print("[DEBUG] Underground state initialized\n");
}

function go_underground(under){
  under ? worldmap.settings.fade_to_ambient_light(0.4, 0.45, 0.6, fade_time) : worldmap.settings.fade_to_ambient_light(1, 1, 1, fade_time);
  Underground_cover.fade(under ? 0 : 1, fade_time);
  Land_foreground_1.fade(under ? 0 : 1, fade_time);
  Land_foreground_2.fade(under ? 0 : 1, fade_time);
  Land_foreground_3.fade(under ? 0 : 1, fade_time);
  Land_foreground_4.fade(under ? 0 : 1, fade_time);
  Underground_mask.fade(under ? 1 : 0, fade_time);
  state.underground <- under;
}

go_underground(state.underground);



// ============================================================================
//   ROAD FORKS
// ============================================================================

if(! ("fitr_down" in state)){
	state.fitr_down <- false;
  print("[DEBUG] 'Fork in the Road' road fork (down) initialized\n");
}

if(! ("fitr_up" in state)){
	state.fitr_up <- false;
  print("[DEBUG] 'Fork in the Road' road fork (up) initialized\n");
}

function reset_forks(fade_time = 0.35) {
  fitr_down.set_solid(state.fitr_down);
  fitr_up.set_solid(state.fitr_up);
  fitr_down_boulder.fade(state.fitr_down ? 0 : 1, fade_time);
  fitr_up_boulder.fade(state.fitr_up ? 0 : 1, fade_time);
}

reset_forks(0.0);


// ============================================================================
//   SECRET AREAS
// ============================================================================

if(! ("fitr_secret" in state)){
	state.fitr_secret <- false;
  print("[DEBUG] 'A Fork in the Road?' secret exit initialized\n");
}

function toggle_secret_exit(tilemap, enabled){
  tilemap.fade(enabled ? 1 : 0, fade_time);
  tilemap.set_solid(enabled);
}

toggle_secret_exit(fitr_secret, state.fitr_secret);


if(! ("liaf_secret" in state)){
	state.liaf_secret <- false;
  print("[DEBUG] 'Living In A Fridge' secret exit initialized\n");
}

function toggle_secret_exit(tilemap, enabled){
  tilemap.fade(enabled ? 1 : 0, fade_time);
  tilemap.set_solid(enabled);
}

toggle_secret_exit(liaf_secret, state.liaf_secret);


if(! ("slsl_secret" in state)){
	state.slsl_secret <- false;
  print("[DEBUG] 'Slippery Slide' secret exit initialized\n");
}

function toggle_secret_exit(tilemap, enabled){
  tilemap.fade(enabled ? 1 : 0, fade_time);
  tilemap.set_solid(enabled);
}

toggle_secret_exit(slsl_secret, state.slsl_secret);
