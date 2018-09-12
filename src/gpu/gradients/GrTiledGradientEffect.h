/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrTiledGradientEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrTiledGradientEffect_DEFINED
#define GrTiledGradientEffect_DEFINED
#include "SkTypes.h"
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
class GrTiledGradientEffect : public GrFragmentProcessor {
public:
    bool mirror() const { return fMirror; }
    static std::unique_ptr<GrFragmentProcessor> Make(
            std::unique_ptr<GrFragmentProcessor> colorizer,
            std::unique_ptr<GrFragmentProcessor> gradLayout, bool mirror) {
        return std::unique_ptr<GrFragmentProcessor>(
                new GrTiledGradientEffect(std::move(colorizer), std::move(gradLayout), mirror));
    }
    GrTiledGradientEffect(const GrTiledGradientEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "TiledGradientEffect"; }

private:
    GrTiledGradientEffect(std::unique_ptr<GrFragmentProcessor> colorizer,
                          std::unique_ptr<GrFragmentProcessor> gradLayout, bool mirror)
            : INHERITED(kGrTiledGradientEffect_ClassID, kNone_OptimizationFlags), fMirror(mirror) {
        this->registerChildProcessor(std::move(colorizer));
        this->registerChildProcessor(std::move(gradLayout));
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    bool fMirror;
    typedef GrFragmentProcessor INHERITED;
};
#endif