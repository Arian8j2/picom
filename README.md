> [!WARNING]
> [Picom](https://github.com/yshui/picom) now has a rich animation system, use it instead. This fork doesn't get any updates but you can achieve a similar animation effect by using this configuration in vanilla Picom:
> ```
> animations = (
>   {
>     triggers = [ "open" ];
>     preset = "appear";
>   },
>   {
>     triggers = [ "close" ];
>     preset = "disappear";
>   },
>   {
>     triggers = [ "geometry" ];
>     offset-x = {
>       curve = "cubic-bezier(0.17, 0.67, 0.68, 1.03)";
>       end = 0;
>       duration = "duration";
>       start = "- offset";
>     };
>     shadow-offset-x = "offset-x";
>
>     # Same as `transition-offset`
>     offset = 100;
>     # Duration of animation in seconds
>     duration = 0.25;
>   }
> )
> ```

# Why another Picom fork?
This fork add **configurable transition animations** to windows.

## How works?
When window moves or get resized, it save new window geometry and then adds static offset (`transition_offset`) to it from direction that you specified (`transition-direction`) and calculate transition based on `transition-timing-function` and `transition-step`.

## Demo
![ezgif-5-dbf86ee80e](https://user-images.githubusercontent.com/56799194/165058556-970aade7-177b-4df0-981e-a8599d20ae69.gif)


- `transition`: enable transition (*bool*)
- `transition-step`: time between frames in transition. (*float*)
- `transition-offset`: offset that gives to window to start transitioning from there (*int*)
- `transition-direction`: direction of transition like *top*, *bottom*, *left*, ... (use *none* for no transition) (*string*)
- `transition-timing-function`: function that used to calculate transition timing, see [easings.net](https://easings.net/) website for list of supported functions, naming convensions are diffrent in that site tho, e.g *easeOutExpo* is *ease-out-expo* here. (*string*)
- `transition-rule` (similar to opacity rule but it changes transition direction) (*list*)

**more info about each config in *picom.sample.conf*.**

## Build and Install
You can build and install from [AUR](https://aur.archlinux.org/packages/picom-arian8j2-git/) or use an AUR helper like `yay` to simplify the process:
```bash
yay -S picom-arian8j2-git
```
checkout [official picom](https://github.com/yshui/picom) to manually build and install from source.
