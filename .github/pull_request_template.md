# Description
Enter a human-readable description of your changes.
(ex): This change includes the mental ability to always choose the right button in a high-pressure situation.

## Changes
Include any additions, changes, or removals here in a concise manner.
Add DAC Algorithms -> PlayStation4
Update DAC Algorithms -> Xbox 360 with `Home` button
Remove DAC Algorithms -> ColecoVision

### Affected Modes
Check the boxes for any mode that is affected by your changes. Make sure to note if these will apply to future modes using a certain DAC algorithm, Communications Protocol, or Button Set.
#### Console
- [X] Nothing Pressed - Melee (Joybus) mode
- [ ] GP2 - P+ (Joybus) mode
- [ ] GP6 - Ultimate (Joybus) mode
- [ ] GP7 - P+ mode
#### USB
- [ ] Nothing Pressed - Melee (Adapter) mode
- [ ] GP0 - 8KRO Keyboard
- [ ] GP2 - Wired Fight Pad Pro with P+
- [ ] GP4 - Wired Fight Pad Pro (dedicated)
- [ ] GP5 - Wired Fight Pad Pro with Melee
- [ ] GP6 - Ultimate (Adapter) mode
- [ ] GP7 - P+ (Adapter) mode
- [ ] GP12 - XInput (Leverless Fightstick via Xbox360)
- [ ] GP13 - XInput with Melee
- [ ] GP14 - XInput (dedicated Xbox360)
- [ ] GP16 - BOOTSEL
- [ ] GP17 - Runtime Remapping
- [ ] GP20 - HID Controller with P+
- [ ] GP21 - HID Controller with Melee
- [ ] GP22 - HID Controller with Ultimate
- [ ] Any other future modes using the Xbox360 DAC Algorithm

### Testing done
Include the steps you took to verify that your changes are operating as intended. Make sure you've covered all possible regressions.
- Verified behavior when holding `A`, plugging into PC via Steam (identified as Xbox 360 controller, all mapped buttons recognized)

### How to reproduce this
Include the steps someone else should take to verify your changes are operating as intended. 
1. Hold `A` button while plugging into PC or Xbox (using a Brooks Wingman XB) to enter Xbox360 dedicated mode.
    1. Verify pressing `Start` immediately wins you the round.
    2. Verify pressing `Start` + `MS` immediately wins you the round, and awards a Perfect (regardless of damange taken).

### Not working
Include anything that isn't working correctly. Include whether or not you caused it.
- When holding `A`, plugging into Playstation4 Pro via Brooks Wingman XE (Controller explodes)
    - Does **not** behavior in upstream (bjart) repo
