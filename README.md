# monitoring-alarm
WC 모니터링용 알람

~+컴퓨터로 반복적인 일할 때 도움 될 것 같음~

# Prerequisite
QT5 권장함
(최소 QT4 이상)

```
#Ubuntu16.04
#sudo apt-get install qt5-default

#arch
#pacman -S qt5-base
```

# Build(Only Linux)
```
cd /project/root/directory

chmod +x install.sh
./install.sh
```

# Executing

## 1. Set environment variable
### For bash
```
cd /project/root/directory

echo export MONITORALARMPATH=$(pwd) >> ~/.bashrc
```

### For zsh
```
cd /project/root/directory

echo export MONITORALARMPATH=$(pwd) >> ~/.zshrc
```

## 2. Restart termial

## 3. Execute
```
cd /project/root/directory

./monitor-alarm
```

# Credit

analog.wav from [soundbible](http://soundbible.com/2197-Analog-Watch-Alarm.html)
