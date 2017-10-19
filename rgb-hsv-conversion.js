// ES6 JS Language

// Get RGB code form HSV
function getRGBFromHSV (hsv) {
    const h = hsv[0] / 60
    const s = hsv[1] / 100
    let v = hsv[2] / 100
    const hi = Math.floor(h) % 6

    const f = h - Math.floor(h)
    let p = 255 * v * (1 - s)
    let q = 255 * v * (1 - (s * f))
    let t = 255 * v * (1 - (s * (1 - f)))
    v *= 255

    v = Math.round(v)
    t = Math.round(t)
    p = Math.round(p)
    q = Math.round(q)

    if (hi === 0) return [v, t, p]
    else if (hi === 1) return [q, v, p]
    else if (hi === 2) return [p, v, t]
    else if (hi === 3) return [p, q, v]
    else if (hi === 4) return [t, p, v]
    else if (hi === 5) return [v, p, q]
  }

// Get HSV code from RGB
function getHSVFromRGB (rgb) {
    const r = rgb[0]
    const g = rgb[1]
    const b = rgb[2]
    const min = Math.min(r, g, b)
    const max = Math.max(r, g, b)
    const delta = max - min
    let h
    const s = max === 0 ? 0 : (delta / max * 1000) / 10
    const v = ((max / 255) * 1000) / 10

    if (max === min) h = 0
    else if (r === max) h = (g - b) / delta
    else if (g === max) h = 2 + ((b - r) / delta)
    else if (b === max) h = 4 + ((r - g) / delta)
    h = Math.min(h * 60, 360)
    if (h < 0) h += 360

    return [Math.round(h), Math.round(s), Math.round(v)]
  }
