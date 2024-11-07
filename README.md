[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<div align="center">
  <a align="center">
    <img src="https://github.com/criogenox/E-Symbolic-Railway-Dynamics-Formulation/assets/53323058/fa3fdd3b-06d8-4c92-aa6f-c53375bcf65a.png" alt="Logo" width="700">
  </a>
  <h3 align="center">Railway applications &#x300A; D &#x300B;</h3>
  <p align="center">
    Database Technical Info Viewer
  </p>
</div>

## About the project

<div align="justify">
  <p>
  
> `C++` application providing a comprehensive graphical interface for managing and visualizing data from a dynamic sql table through customizable dockable windows.

`Key Features:`
- Image viewing: it displays formats with zoom and pan capabilities.
- Dock management: create, close, and restore dock windows on demand.
- Data interaction: manipulating data directly from a SQLite database.
- Clean GUI: responsive layout adapting to multiple resize events.
   </p>
       <p align="right">
    :muscle: don't let anyone get you down :muscle:
  </p> 
   <div>

## Key Methods

<div align="justify">
  <p>

> Dynamic creation of dock widgets for displaying information related to a specified table.

`Functionalities:`
- Checks for existing docks with the same name to prevent duplicates.
- Restoration of closed docks to their previous geometry, while preventing the creation of new ones.

> Handling view size fitting in response to several resizing events (including image initial loading).

`Functionality:`
- Updates the view/scene size to fit the new dimensions generated due to mainwindow rescaling, dock's area/size changes or splitter movements.

> Overriding of several mouse events for graphical managing of loaded images.

`Functionalities:`
- Handles mouse press events to dragging and panning (warning, inverted mouse buttons).
- Focus zooming on cursor position disabling the vertical scrollbar to enhance zoom experience.
- Handles double-click events to fit the scene within the view, keeping the aspect ratio.
   </p>
   <div>

<p align="right">(<a href="#top">back to top</a>)</p>

## Built With

<div style="display: flex; flex-direction: column; align=center">
    <img class="img"src="https://github.com/criogenox/B_ECC-Cpp-version_plot-capabilities_noGUI/assets/53323058/1fdf2d22-fb04-45aa-9db0-8bd973942914.png" alt="Logo" width="100" height="90"/>
    <img class="img"src="https://github.com/criogenox/D-Technical-Railway-Data-Viewer-from-SQLitedb/assets/53323058/c17664ed-56c6-4479-959c-844f744bc47b.png" alt="Logo" width="150" height="85"/>
    <img class="img"src="https://github.com/criogenox/B_ECC-Cpp-version_plot-capabilities_noGUI/assets/53323058/6870b0b2-403c-49da-b745-5714b08f4a73.png" alt="Logo" width="100" height="90"/>
    <img class="img"src="https://github.com/criogenox/B_ECC-Cpp-version_plot-capabilities_noGUI/assets/53323058/781b169a-440c-4c8a-9fbb-caa5ce150d13.png" alt="Logo" width="90" height="85"/>

### Additional info

* `Extensive` checking of instance deletion to ensure proper and effective resource management, preventing memory leaks.
* Widget `stylizing` by a modified theme based on the extremely useful original contribution [QT DarkTheme][qtdarktheme-url].

##  General view sample

<div align="justify"> 
  <!-- <img align="right" src="https://user-images.githubusercontent.com/53323058/230650942-4c2e0ad4-2d52-46fe-aa67-8860c642e5f6.png" width="500"> -->
<img align="center" src="https://github.com/criogenox/D-Technical-Railway-Data-Viewer-from-SQLitedb/assets/53323058/3346ae8d-bf79-49cc-b1fd-292e3448c33c.png">
   </p>
       <p align="center">
Full functionalities in use:  clickable table index, independent views with their corresponding dock info.
  </p> 
</div>

<!-- ROADMAP -->
## TODO

- [ ] Completely populate the database.
- [ ] Logic implementation for all selection cases.
- [ ] Improve error handling.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See [LICENSE.txt][license-url] for more information.

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[linkedin-shield]: https://user-images.githubusercontent.com/53323058/230575198-fa1acbf4-8f82-4d8e-b245-3979276bc240.png
[linkedin-url]: https://www.linkedin.com/in/criogenox/
[qtdarktheme-url]: https://github.com/keshav-sahu7/qt-dark-theme
[license-url]: https://github.com/criogenox/D-Technical-Railway-Data-Viewer-from-SQLitedb/tree/main?tab=MIT-1-ov-file
