[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<div align="center">
  <a align="center">
    <img src="https://github.com/criogenox/E-Symbolic-Railway-Dynamics-Formulation/assets/53323058/4b126ff6-1d93-40ec-911c-9ffca3eb7abb.png" alt="Logo" width="700">
  </a>
  <h3 align="center">Railway applications &#x300A; E &#x300B;</h3>
  <p align="center">
    Database Technical Info Viewer
  </p>
</div>

## About the project

<div align="justify">
  <p>
  
> The global goal: develop a tool to aid the process of complex mechanical systems' simulation, mainly focused on railway vehicles and especially, on articulated modular railcar models. It also enhances the ease of writing documentation, reports, and academic papers, where lengthy equations or complex mathematical expressions need to be used.
   </p>
       <p align="right">
    :muscle: don't let anyone get you down :muscle:
  </p> 
   <div>

## Current Status

<div align="justify">
  <p>

The initial phase of the project has been developed, which involves the functionality to `translate standard mathematical expressions`, used generally in dynamical formulations, into `LaTeX formatting`. The given developed tool will enable users to focus on analysis and interpretation, rather than formatting the result, by providing a seamless way to convert equations into a clear and visually appealing, and efficiently document their insights. 

`Currently eatures:`

- Support for derivatives, super/subscripts, special characters, and several operators. Detailed documentation for these features can be found in here.
  
   </p>
   <div>

<p align="right">(<a href="#top">back to top</a>)</p>

## Work in progress

<div align="justify">
  <p>
    
**`Direct conversion from GiNaC formulae`**
 
> The previous mentioned library (eqs2latex) takes as input the result of the processed expressions originated from the formulation of systems of dynamical equations, represented in symbolic form using GiNaC C++ library.
   </p>
   <div>
     
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
