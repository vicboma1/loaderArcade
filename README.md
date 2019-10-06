# Loader Dumps Arcade

#### All this is a homebrew development with reverse engineering, non official technical documentation and a lot of personal time. 
Twitter : https://twitter.com/vicboma1

## Indexes 

### [Systems](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#systems-1)
* [Taito Type x](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#taito-type-x)
* [Taito Type x2](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#taito-type-x2)
* [NESiCAxLive](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#nesicaxlive)

### Loader
* [Injections](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#loader--based-on-injections)

### [Inputs](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#inputs-1)
* [Keyboard/Joystick](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#keyboardjoystick)
* [Direct Input](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#direct-input--based-on-hooks)
* [Async-KeyState](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#getasynckeystate)
* [Examples](https://github.com/vicboma1/loaderDumpsArcade/blob/master/README.md#example)

### [JVS I/O](https://github.com/vicboma1/loaderDumpsArcade#jvs-io)

### [Graphics](https://github.com/vicboma1/loaderDumpsArcade#graphics-wip)
 * [High Resolution](https://github.com/vicboma1/loaderDumpsArcade#graphics-wip)

### [Sound](https://github.com/vicboma1/loaderDumpsArcade#graphics-wip)
### [GUI](https://github.com/vicboma1/loaderDumpsArcade#gui)
### [Systems/Games Loaders](https://github.com/vicboma1/loaderDumpsArcade#systemsgames-loaders-wip--video-playlist)
### [Code Ratio](https://github.com/vicboma1/loaderDumpsArcade#code-ratio)
### [References](https://github.com/vicboma1/loaderDumpsArcade#references)


## Systems
 
 ### Taito Type x
    ```
    Year : 2005
    CPU : Celeron - Pentium 4
    Chipset: Intel 865G
    GPU: ATI Radeon 9600SE/9600XT(128 MB) / X700PRO (256 MB), Bahia AGP 2.0/3.0 Soporte 1x/4x/8x
    SO: Windows XP Embedded
    ```
    
### Taito Type x2
  ```
    Year : 2005
    CPU : Intel Core 2 Duo E6400／Pentium 4 651／Celeron D 352
    Chipset: Intel Q965 + ICH8
    GPU: ATI RADEON X1600Pro/X1300LE o nVIDIA GeForce 7900GS／7600GS／7300GS
    SO: Microsoft Windows XP Embedded SP2
  ```

### NESiCAxLive
  ```
    Arcade System Board
    Run w/ Taito Type X, X2, X Zero, X3 and X4
  ```
  
## Loader | [Based on Injection's](https://github.com/vicboma1/Inject-DLL#process)
   ```C
    public interface ILoaderProcessNative
    {
        Boolean isLoaded { get; }
        Boolean isActive();

        int Open(String name);
        Task OpenAsync(String name);

        Kernel32Native.PROCESS_INFORMATION Create(String name, uint securityAttr);

        Boolean Attach(String name);
        Boolean InjectDLL(String name);

        List<IntPtr> SuspendAllThreads();
          
        Boolean ReadMemory(IntPtr processID, IntPtr address, int numOfBytes, byte[] buffer, out int bytesRead);
        Boolean WriteMemory(IntPtr hProc, IntPtr address, byte [] buffer, out int bytesWrited);

        List<IntPtr> ResumeAllThreads();

        Boolean Terminate();
    }
   
   ```
   
## Inputs

### Keyboard/Joystick  

### Direct Input | [Based on Hook's](https://github.com/vicboma1/Inject-DLL#hooks)
 * [DIKCode](http://www.flint.jp/misc/?q=dik&lang=en)
 
### [GetAsyncKeyState](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
 * [OpCode](https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes)

  
## Example

 * Player 1
   ```
   [Display address]  [Value]  [Byte]  [Key]
   0000000000000000     00       .     Start
   0000000000000004     00       .     Coin
   0000000000000008     00       .     Service
   000000000000000C     00       .     Up
   0000000000000010     00       .     Down
   0000000000000014     00       .     Left
   0000000000000018     00       .     Right
   000000000000001C     00       .     Btn 1
   0000000000000020     00       .     Btn 2
   0000000000000024     00       .     Btn 3
   0000000000000028     00       .     Btn 4
   000000000000002C     00       .     Btn 5 
   0000000000000030     00       .     Btn 6
   ```
    
* Player 2
  ```
  [Display address]  [Value]  [Byte]  [Key] 
  0000000000000034     00       .     Start
  0000000000000038     00       .     Coin
  000000000000003C     00       .     Service
  0000000000000040     00       .     Up
  0000000000000044     00       .     Down
  0000000000000048     00       .     Left
  000000000000004C     00       .     Right
  0000000000000050     00       .     Btn 1
  0000000000000054     00       .     Btn 2
  0000000000000058     00       .     Btn 3
  000000000000005C     00       .     Btn 4
  0000000000000060     00       .     Btn 5 
  0000000000000064     00       .     Btn 6
  ```

* Board 
  ```
  [Display address]  [Value]  [Byte]  [Key]
  0000000000000068     00       .     Test Mode
  000000000000006C     00       .     Exit
  ```
  
* Assets | 'binding'.bin
  ```
  Need for the taito type x game to read the keyboard input 
  
  Keyboard    -  256 (short)
  0x000000XX     XX     
    
  Joystick    -  X[1|2]   -  Axis[+|-][X|Y|Z]   -  256 (btn)
  0xZXYA0CMN       ZY     -        YA           -    0CMN      
  
 
  Example
 
  [Display address]        [Hexa Code]             [Hexa Code]          [Ascii Code]
  0000000000000000  02 00 00 00 06 00 00 00  06 00 00 00 C8 00 00 00  ................
  0000000000000010  D0 00 00 00 CB 00 00 00  CD 00 00 00 02 00 00 00  ................
  0000000000000020  03 00 00 00 04 00 00 00  05 00 00 00 06 00 00 00  ................
  0000000000000030  07 00 00 00 32 00 00 00  31 00 00 00 30 00 00 00  ....2...1...0...
  0000000000000040  2F 00 00 00 2E 00 00 00  01 00 00 X1 03 00 00 X1  /...............
  0000000000000050  02 00 00 X1 25 00 00 00  24 00 00 00 23 00 00 00  ........$...#...
  0000000000000060  22 00 00 00 21 00 00 00  14 00 00 00 01 00 00 00  "...!...........         
  ```
   
* Example | scratch (PoF with vs2010)

   ![](https://raw.githubusercontent.com/vicboma1/loaderDumpsArcade/master/assets/images/InputMapping2P_v2.gif)
  
#### JVS I/O
```
Inicializando
	Logger: 2019-06-07_00-48-04-LoggerJvs.log 

	Escribo  6 bytes... -> [ E0 FF 03 F0 D9 CB ] 0xE0FF03F0D9CB
	[E0] = SYNC_CODE OK
	[FF] = BROADCAST A TODOS LOS NODOS
	[03] = 
	[F0] = RESET ALL NODES
	[D9] 
	[CB] = 
	Envío    0 bytes... -> [ ]

............................

	Escribo  6 bytes... -> [ E0 FF 03 F1 01 F4 ] 0xE0FF03F101F4
	[E0] = SYNC_CODE OK
	[FF] = BROADCAST A TODOS LOS NODOS
	[03] = 
	[F1] = Set Address
	[01] 
	[F4] = 
	Envío    6 bytes... -> [ XXXXXXXXXXX ]

............................

	Escribo  5 bytes... -> [ E0 01 02 10 13 ]  0xE001021013 
	[E0] = SYNC_CODE OK
	[01] = ESCLAVO
	[02] = 
	[10] = I/O IDENTIFICADOR 
	[13] = 
	Envío    58 bytes... -> [ XXXXXXXXXXX ]

............................

	Escribo  5 bytes... -> [ E0 01 02 11 14 ] 0xE001021114 
	[E0] = SYNC_CODE OK
	[01] = ESCLAVO
	[02] = 
	[11] = COMANDO REVISION FORMATO 
	[14] = 
	Envío    7 bytes... -> [ XXXXXXXXXXX ]
	
	...
```

## Graphics (wip)

#### High Resolution (wip)

## Sound (wip)

##  GUI

* scratch (Pof with vs2010) (wip)
   
   ![](https://raw.githubusercontent.com/vicboma1/loaderDumpsArcade/master/assets/images/GUI_v.0.0.1.gif)
  
## Systems/Games Loaders (wip) | [Video PlayList](https://www.youtube.com/playlist?list=PLNph7ndeSqE-ipUjV17uCQ-ZMGs9VC7CH)

### Taito Type x
* [Cosplay 3D Mahjong - 706]() - Working Video | Inputs (WIP)

* [Rastan Saga - 882 | Working 100%](https://youtu.be/pGB89NVwNDg) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/rastanSagattx.gif" width="800" height="480" />

* [Raiden III Arcade (2005) | Working 100%](https://www.youtube.com/watch?v=L5Bl5P3vHvo)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/raiden3_3.gif" width="800" height="480" />

* [Raiden III Arcade (2005) | Hack Filters in Runtime | Working 100%](https://youtu.be/wKgiJ981Utw) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/raiden32.gif" width="800" height="480" />

* [Raiden III Arcade (2005) | Creating a voxel Hack which cancels the inner toplights for the main sprite | Working 100%](https://youtu.be/1fW33Jc9ZZ8) 
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/Raiden3_Light_60_.gif" width="800" height="480" />

* [Raiden IV (雷電IV Raiden Fō) Arcade (2007) | Fullscreen & Rotation Display | WIP ](https://youtu.be/byBMfUstYLY) 
<img src="http://s3.amazonaws.com/snd-store/a/26553114/02_02_18_508408464_aab_560x292.jpg" width="800" height="480" />

### Taito Type x2
* [Trouble Witches AC | Working 100%](https://youtu.be/d0Eo7ataLvg)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/troubleWitches5.gif" width="800" height="480" />

* [Trouble Witches AC | Hack Hidden Background | Working 100%](https://youtu.be/ZytAryfM6Y0)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/brujasHack2_600.gif" width="800" height="480" />

* [Trouble Witches AC | Hack Rendered entities without alpha | Working 100%](https://www.youtube.com/watch?v=hwjk6pUyw8g)
<img src="https://github.com/vicboma1/loaderDumpsArcade/blob/master/assets/images/_h2.gif" width="800" height="480" />


### NesicaxLive
* [Cosplay 3D Mahjong - 401300]() - Video (WIP)
* [Rastan Saga - 401500]() - Inputs (WIP)
* [Puzzle Bobble - 301200 ]() - Inputs (WIP)

# Code Ratio

```
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
XML                            114            173            345         282779
C/C++ Header                   736          36663          81900         140867
C#                             101           1267           3550           8267
C++                             54           2209           2609           8016
C                                8            393            364           5277
MSBuild script                  16              0             49           1532
INI                              5            107             91            531
Markdown                         2              4              0             44
XAML                             2              1              0             15
JSON                             6              0              0              6
DOS Batch                        1              0              0              3
Bourne Shell                     1              0              1              2
-------------------------------------------------------------------------------
SUM:                          1046          40817          88909         447339
-------------------------------------------------------------------------------
```

# References
 * [JVS vs JAMMA](http://forum.arcadecontrols.com/index.php?topic=95942.0)
 * [JVS conversion](https://wiki.arcadeotaku.com/images/9/97/SEGA_cabinet_JVS_conversion_manual_.pdf)
 * [JVS protocols](https://wiki.arcadeotaku.com/w/JVS)
 * [Jamma Video Standard](http://daifukkat.su/files/jvs_wip.pdf)
 * [Naomi I/O Board](https://wiki.arcadeotaku.com/images/d/db/Capcom_io_jp_manual.pdf)
 * [Manual Programmer NV API ](https://github.com/vicboma1/loaderDumpsArcade/raw/master/assets/images/NVControlPanel_API.pdf)
 * [JVS](http://superusr.free.fr/arcade/JVS/JVST_VER3.pdf)
 * [JVS Original](https://github.com/vicboma1/loaderDumpsArcade/raw/master/assets/images/JVSR.pdf)
 * [I/O Board](https://github.com/reicast/reicast-emulator/blob/master/core/hw/maple/maple_devs.cpp)
 * [Input Keys](http://www.flint.jp/misc/?q=dik&lang=en)
 * [Cloc](https://es.osdn.net/projects/sfnet_cloc/)
 
# No roms, no games, no dumps! 
