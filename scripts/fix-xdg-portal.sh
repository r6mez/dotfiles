
export XDG_CURRENT_DESKTOP=Hyprland


echo 'export XDG_CURRENT_DESKTOP=Hyprland' >> ~/.bashrc
source ~/.bashrc

#!/usr/bin/env bash
export XDG_CURRENT_DESKTOP=Hyprland
sleep 1
killall -e xdg-desktop-portal-hyprland
killall -e xdg-desktop-portal-wlr
killall xdg-desktop-portal
/usr/lib/xdg-desktop-portal-hyprland &
sleep 2
/usr/lib/xdg-desktop-portal &
