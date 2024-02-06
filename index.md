---
layout: start
title: Getting Started
permalink: /
sequence: 1

manufacturing: false
downloads:
  schematic: true
  layout: false
  kicad: true
  gerber: false
  bom: true
  case: true
features:
  - detail: Turn off door bell audio based on time of the day E.g. sleeping
  - detail: Add a timeout so that repeated door bell rings are not annoying
  - detail: Connect to WiFi and send a webhook to Zapier for future integrations
  - detail: (Integration) Turn on a light signal when the door bell rings and the sound is off E.g. in a Zoom call
  - detail: (Integration) Send a mobile notification
---
<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Getting Started</h2>
    <div class="tile is-ancestor">
      <div class="tile is-vertical is-12">
        <div class="tile">
          <div class="tile is-parent">
            <article class="tile is-child notification">
              <p class="title">Teardown</p>
              <p class="subtitle">Look into the internals of an existing <a href="https://s.click.aliexpress.com/e/_Dm6bTXf">wired battery-powered doorbell from FUERS</a> bought on AliExpress, priced below USD $4.00.</p>
              <a href="{{site.url}}/images/prototype/initial-doorbell.jpg">
                <img src="{{site.url}}/images/prototype/initial-doorbell.jpg" alt="FUERS Wired Guest Welcome Doorbell High Quality Energy-saving Door bell Simple Generous Home Store Security Doorbell Button">
              </a>
              <a href="{{site.url}}/images/prototype/prototype-3.jpg">
                <img src="{{site.url}}/images/prototype/prototype-3.jpg" alt="FUERS Wired Guest Welcome Doorbell High Quality Energy-saving Door bell Simple Generous Home Store Security Doorbell Button">
              </a>
              <p class="title">Battery</p>
              <p class="subtitle">It is powered by 2 AAA batteries</p>
              <a href="{{site.url}}/images/prototype/initial-doorbell-power.jpg">
                <img src="{{site.url}}/images/prototype/initial-doorbell-power.jpg" alt="Power by 2 AAA batteries">
              </a>
            </article>
          </div>
          <div class="tile is-parent">
            <article class="tile is-child notification">
              <p class="title">Chip</p>
              <p class="subtitle">Chip <a href="https://www.yoycart.com/Product/550682313846/">TQ33E-11</a> is used. It rings "Ding Dong"  2 times. It is a Music chip with a built-in transistor positive trigger.</p>
              <a href="{{site.url}}/images/prototype/initial-doorbell-chip.jpg">
                <img src="{{site.url}}/images/prototype/initial-doorbell-chip.jpg" alt="Chip of the original doorbell">
              </a>
              <a href="{{site.url}}/images/prototype/initial-doorbell-circuit.jpeg">
                <img src="{{site.url}}/images/prototype/initial-doorbell-circuit.jpeg" alt="Chip circuit">
              </a>
              <a href="{{site.url}}/images/prototype/initial-doorbell-chip-back.jpg">
                <img src="{{site.url}}/images/prototype/initial-doorbell-chip-back.jpg" alt="Back of the Chip of the original doorbell">
              </a>
            </article>
          </div>
          <div class="tile is-parent">
            <article class="tile is-child notification">
              <p class="title">Prototype</p>
              <p class="subtitle">Wire up the TQ33E-11 chip with breadboard.</p>
              <a href="{{site.url}}/images/pcb/schematic.png">
                <img src="{{site.url}}/images/pcb/schematic.png" alt="Schematic of the breadboard">
              </a>
              <a href="{{site.url}}/images/prototype/front.jpg">
                <img src="{{site.url}}/images/prototype/front.jpg" alt="Prototype">
              </a>
              <p class="subtitle">Upload the <a href="/code/demo#code">firmware</a> and view the serial monitor.</p>
              <a href="{{site.url}}/images/code/demo-console.png">
                <img src="{{site.url}}/images/code/demo-console.png" alt="Serial monitor">
              </a>
            </article>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Thanks 🤗</h2>
    <div class="content is-medium">
      <ul>
        <li><a href="https://chinmay.audio/">Chinmay</a> for review, soldering and testing</li>
        <li><a href="https://www.reddit.com/r/PrintedCircuitBoard/comments/1ag6j6m/review_request_esp32c3_based_board_to_retrofit_a/">Reddit ccommunity</a> for review comments</li>
      </ul>
    </div>
  </div>
</section>
