const delay = d => new Promise(res => setTimeout(res, d))

const buttons = [...document.querySelectorAll('.button')]
    , example = document.querySelector('.example')
    , canvas = document.querySelector('canvas')
    , ctx = canvas.getContext('2d')

let state = {
  ds: false,
  st_cp: false,
  sh_cp: false
}

const graph = Array(30).fill(1).map(() => state);

const render = () => {
  ctx.clearRect(0, 0, 110, 63)
  ctx.fillStyle = '#0BE2F0'

  graph.forEach(({ ds, st_cp, sh_cp }, x) => {
    if (graph[x+1] && graph[x].sh_cp !== graph[x+1].sh_cp) {
      ctx.fillRect((x * 4) + 2, 10 - 5, 2, 7);
    }

    if (graph[x+1] && graph[x].ds !== graph[x+1].ds) {
      ctx.fillRect((x * 4) + 2, 31 - 5, 2, 7);
    }

    if (graph[x+1] && graph[x].st_cp !== graph[x+1].st_cp) {
      ctx.fillRect((x * 4) + 2, 53 - 5, 2, 7);
    }

    ctx.fillRect(x * 4, sh_cp ? 10 - 5 : 10, 4, 2);
    ctx.fillRect(x * 4, ds ? 31 - 5 : 31, 4, 2);
    ctx.fillRect(x * 4, st_cp ? 53 - 5 : 53 , 4, 2);
  })
}
render()

const resize = () => {
  const width = window.innerWidth
      , height = window.innerHeight

  const minSize = width > height ? height : width

  const scale = minSize / 580

  example.style.transform = `scale(${scale})`
}

resize()
window.addEventListener('resize', resize)

buttons.map(button => {
  button.addEventListener('click', () => {
    const className = button.getAttribute('class')

    state = {
      ...state,
      [button.getAttribute('type')]: !className.match('active')
    }

    graph.unshift(state)

    render()

    className.match('active')
      ? button.setAttribute('class', className.replace('-active', ''))
      : button.setAttribute('class', className + '-active')
  })
})

const ST_CP = state => {
  const className = buttons[0].getAttribute('class')
  state
    ? buttons[0].setAttribute('class', className.replace('-active', '') + '-active')
    : buttons[0].setAttribute('class', className.replace('-active', ''))
  buttons[0].click()
}
const SH_CP = state => {
  const className = buttons[1].getAttribute('class')
  state
    ? buttons[1].setAttribute('class', className.replace('-active', '') + '-active')
    : buttons[1].setAttribute('class', className.replace('-active', ''))
  buttons[1].click()
}
const DS = state => {
  const className = buttons[2].getAttribute('class')
  state
    ? buttons[2].setAttribute('class', className.replace('-active', '') + '-active')
    : buttons[2].setAttribute('class', className.replace('-active', ''))
  buttons[2].click()
}

const play = async () => {
  const inputs = document.querySelectorAll('input')
      , lights = [...document.querySelectorAll('.light')]
      , bits = inputs[1].value.split('')
      , d = parseInt(inputs[0].value)

  ST_CP(0)
  await delay(d)
  for (let i = 0; i < 8; i++) {
      await delay(d)
      SH_CP(0)
      await delay(d)
      DS(parseInt(bits[i]))
      await delay(d)
      SH_CP(1)
  }
  await delay(d)
  ST_CP(1)

  lights.map((light, i) =>
    light.style.background = parseInt(bits[i] || 0) ? 'radial-gradient(50% 50% at 50% 50%, #FF1F1F 0%, rgba(255, 31, 31, 0.58) 53.65%, rgba(255, 31, 31, 0.595909) 67.71%, rgba(255, 31, 31, 0) 100%)' : 'rgba(0, 0, 0, 0)'
  )
}
